/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_CONNECTIONMODULE_HPP_
#define CONNECTION_CONNECTIONMODULE_HPP_

#include <connection/workers/IWorker.hpp>

#include <log/ILogger.hpp>
#include <connection/hci/IHciObjectsBuilder.hpp>
#include <connection/hci/ISubscriptionsStorage.hpp>

#include <list>
#include <memory>
#include <thread>

namespace connection
{

class ConnectionModule
{
public:
    ConnectionModule();

    void activate();

private:
    const std::string M_WORKER_LOGGER_NAME{"CONNECTION"};
    std::unique_ptr<common::log::ILogger> m_logger;

    std::shared_ptr<hci::ISubscriptionsStorage> m_subscriptions_storage;
    std::shared_ptr<hci::IHciObjectsBuilder> m_hci_objects_builder;
    std::list<std::unique_ptr<workers::IWorker>> m_workers;
    std::list<std::thread> m_threads;
};

} // namespace connection

#endif // CONNECTION_CONNECTIONMODULE_HPP_
