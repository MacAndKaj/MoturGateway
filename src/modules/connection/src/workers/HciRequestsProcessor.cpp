/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include <connection/workers/HciRequestsProcessor.hpp>

#include <log/MainLogger.hpp>
#include <connection/hci/SubscriptionsStorage.hpp>
#include <connection/hci/HciObjectsBuilder.hpp>
#include <connection/utils/ConnectionContext.hpp>
#include <exceptions/IMoturException.hpp>

#include <csignal>
#include <iostream>
#include <thread>

namespace connection::workers
{

HciRequestsProcessor::HciRequestsProcessor(std::shared_ptr<hci::ISubscriptionsStorage> subscriptions_storage,
                                           std::shared_ptr<hci::IHciObjectsBuilder> hci_objects_builder)
    : m_subscriptions_storage(std::move(subscriptions_storage))
    , m_hci_objects_builder(std::move(hci_objects_builder))
{
}

HciRequestsProcessor::~HciRequestsProcessor()
{
    m_is_running = false;
}

void HciRequestsProcessor::run()
{
    utils::ConnectionContext context;
    context.setLogger(std::make_unique<common::log::MainLogger>(M_WORKER_LOGGER_NAME));
    auto& logger = context.getLogger();
    logger.info("[HciRequestsProcessor] Configuring worker");

    {
        context.setSubscriptionsStorage(m_subscriptions_storage);
        context.setHciObjectsBuilder(m_hci_objects_builder);
    }

    try
    {
        logger.info("[HciRequestsProcessor] Worker configured correctly. Enter main loop.");
        m_is_running = true;

        constexpr std::chrono::milliseconds interval(1);
        while (m_is_running)
        {
            std::this_thread::sleep_for(interval); //TODO: find other way to decrease CPU usage
        }
    }
    catch (const common::exceptions::IMoturException& ex)
    {
        context.getLogger().err("[HciRequestsProcessor] Motur exception occured in runtime.");
        context.getLogger().err("[HciRequestsProcessor] " + std::string(ex.what()));
        forceStop();
    }
    catch (const std::exception& ex)
    {
        context.getLogger().err("[HciRequestsProcessor] Unknown fatal exception occured in runtime.");
        context.getLogger().err("[HciRequestsProcessor] " + std::string(ex.what()));
        forceStop();
    }
    catch (...)
    {
        context.getLogger().err("[HciRequestsProcessor] Unknown exception occured");
        forceStop();
    }
}

void HciRequestsProcessor::forceStop()
{
    std::raise(SIGINT);
}

} // namespace connection::workers
