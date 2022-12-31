/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include <connection/workers/HciAsyncEventsDispatcher.hpp>

#include <log/MainLogger.hpp>
#include <connection/hci/SubscriptionsStorage.hpp>
#include <connection/hci/HciObjectsBuilder.hpp>
#include <connection/utils/ConnectionContext.hpp>
#include <connection/hci/HciPoller.hpp>
#include <exceptions/IMoturException.hpp>

#include <csignal>
#include <iostream>
#include <thread>

namespace connection::workers
{

HciAsyncEventsDispatcher::HciAsyncEventsDispatcher(std::shared_ptr<hci::ISubscriptionsStorage> subscriptions_storage,
    std::shared_ptr<hci::IHciObjectsBuilder> hci_objects_builder)
    : m_subscriptions_storage(std::move(subscriptions_storage))
    , m_hci_objects_builder(std::move(hci_objects_builder))
{
}

HciAsyncEventsDispatcher::~HciAsyncEventsDispatcher()
{
    m_is_running = false;
}

void HciAsyncEventsDispatcher::run()
{
    utils::ConnectionContext context;
    context.setLogger(std::make_unique<common::log::MainLogger>(M_WORKER_LOGGER_NAME));
    auto& logger = context.getLogger();
    logger.info("[HciAsyncEventsDispatcher] Configuring worker");

    {
        context.setSubscriptionsStorage(m_subscriptions_storage);
        context.setHciObjectsBuilder(m_hci_objects_builder);
    }

    try
    {
        hci::HciPoller poller(context);
        logger.info("[HciAsyncEventsDispatcher] Worker configured correctly. Enter main loop.");
        m_is_running = true;

        constexpr std::chrono::milliseconds interval(1);
        while (m_is_running)
        {
            poller.work();
            std::this_thread::sleep_for(interval); //TODO: find other way to decrease CPU usage
        }
    }
    catch (const common::exceptions::IMoturException& ex)
    {
        context.getLogger().err("[HciAsyncEventsDispatcher] Motur exception occured in runtime.");
        context.getLogger().err("[HciAsyncEventsDispatcher] " + std::string(ex.what()));
        forceStop();
    }
    catch (const std::exception& ex)
    {
        context.getLogger().err("[HciAsyncEventsDispatcher] Unknown fatal exception occured in runtime.");
        context.getLogger().err("[HciAsyncEventsDispatcher] " + std::string(ex.what()));
        forceStop();
    }
    catch (...)
    {
        context.getLogger().err("[HciAsyncEventsDispatcher] Unknown exception occured");
        forceStop();
    }
}

void HciAsyncEventsDispatcher::forceStop()
{
    std::raise(SIGINT);
}

} // namespace connection::workers
