/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/ConnectionModule.hpp>

#include <log/MainLogger.hpp>
#include <connection/workers/ConnectionManager.hpp>
#include <connection/workers/HciAsyncEventsDispatcher.hpp>
#include <connection/hci/SubscriptionsStorage.hpp>
#include <connection/hci/HciObjectsBuilder.hpp>

namespace connection
{

ConnectionModule::ConnectionModule()
    : m_logger(std::make_unique<common::log::MainLogger>(M_WORKER_LOGGER_NAME))
{
    m_subscriptions_storage = std::make_shared<hci::SubscriptionsStorage>(*m_logger);
    m_hci_objects_builder = std::make_shared<hci::HciObjectsBuilder>(*m_logger);

    m_workers.push_back(std::make_unique<workers::HciAsyncEventsDispatcher>(m_subscriptions_storage, m_hci_objects_builder));
    m_workers.push_back(std::make_unique<workers::ConnectionManager>(m_subscriptions_storage, m_hci_objects_builder));
}

void ConnectionModule::activate()
{
    for(auto& worker : m_workers)
    {
        m_threads.emplace_back(std::thread([&](){
            (*worker).run();
        }));
    }
}



} // namespace connection
