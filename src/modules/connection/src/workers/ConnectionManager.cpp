/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include <connection/workers/ConnectionManager.hpp>

#include <connection/conn_ctrl/ConnectionControl.hpp>
#include <connection/utils/ConnectionContext.hpp>
#include <exceptions/IMoturException.hpp>
#include <log/MainLogger.hpp>

#include <csignal>
#include <thread>

namespace connection::workers
{

ConnectionManager::ConnectionManager(std::shared_ptr<hci::ISubscriptionsStorage> subscriptions_storage,
                  std::shared_ptr<hci::IHciObjectsBuilder> hci_objects_builder)
    : m_subscriptions_storage(std::move(subscriptions_storage))
    , m_hci_objects_builder(std::move(hci_objects_builder))
{
}

void ConnectionManager::run()
{
    utils::ConnectionContext context;
    context.setLogger(std::make_unique<common::log::MainLogger>(M_WORKER_LOGGER_NAME));
    auto& logger = context.getLogger();
    logger.info("[ConnectionManager] Configuring worker");

    {
        context.setSubscriptionsStorage(m_subscriptions_storage);
        context.setHciObjectsBuilder(m_hci_objects_builder);
    }

    try
    {
        conn_ctrl::ConnectionControl connection_control(context);
        logger.info("[ConnectionManager] Worker configured correctly. Enter main loop.");

        m_is_running = true;
        constexpr std::chrono::milliseconds interval(1);
        while (m_is_running)
        {
            connection_control.process();
            std::this_thread::sleep_for(interval); //TODO: find other way to decrease CPU usage
        }
    }
    catch (const common::exceptions::IMoturException& ex)
    {
        context.getLogger().err("[ConnectionManager] Motur exception occured in runtime.");
        context.getLogger().err("[ConnectionManager] " + std::string(ex.what()));
        forceStop();
    }
    catch (const std::exception& ex)
    {
        context.getLogger().err("[ConnectionManager] Unknown fatal exception occured in runtime.");
        context.getLogger().err("[ConnectionManager] " + std::string(ex.what()));
        forceStop();
    }
    catch (...)
    {
        context.getLogger().err("[ConnectionManager] Unknown exception occured");
        forceStop();
    }
}

void ConnectionManager::forceStop()
{
    std::raise(SIGINT);
}

} // namespace connection::workers
