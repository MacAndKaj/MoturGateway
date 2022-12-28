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

void HciAsyncEventsDispatcher::run()
{
    utils::ConnectionContext context;
    context.setLogger(std::make_unique<common::log::MainLogger>(M_WORKER_LOGGER_NAME));
    auto& logger = context.getLogger();
    logger.info("[HciAsyncEventsDispatcher] Configuring worker");

    {
        context.setSubscriptionsStorage(std::make_unique<hci::SubscriptionsStorage>(logger));
        context.setHciObjectsBuilder(std::make_unique<hci::HciObjectsBuilder>(logger));
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
