/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/ConnectionModule.hpp>

#include <log/MainLogger.hpp>
#include <connection/hci/SubscriptionsStorage.hpp>
#include <connection/hci/HciObjectsBuilder.hpp>
#include <connection/workers/ConnectionManager.hpp>
#include <connection/workers/HciAsyncEventsDispatcher.hpp>
#include <connection/workers/HciRequestsProcessor.hpp>

namespace connection
{

ConnectionModule::ConnectionModule()
    : m_logger(std::make_unique<common::log::MainLogger>(M_WORKER_LOGGER_NAME))
{
    m_subscriptions_storage = std::make_shared<hci::SubscriptionsStorage>(*m_logger);
    m_hci_objects_builder = std::make_shared<hci::HciObjectsBuilder>(*m_logger);

    m_workers.emplace_back(std::make_unique<workers::HciAsyncEventsDispatcher>(m_subscriptions_storage, m_hci_objects_builder));
    m_workers.emplace_back(std::make_unique<workers::HciRequestsProcessor>(m_subscriptions_storage, m_hci_objects_builder));
    m_workers.emplace_back(std::make_unique<workers::ConnectionManager>(m_subscriptions_storage, m_hci_objects_builder));
}

ConnectionModule::~ConnectionModule()
{
    for (auto& w : m_workers)
    {
        w->stop();
    }

    for (auto& t : m_threads)
    {
        if (t.joinable())
        {
            t.join();
        }
    }
}

void ConnectionModule::activate()
{
    for(auto& worker : m_workers)
    {
        m_threads.emplace_back([&](){
            (*worker).run();
        });
    }

    m_threads.emplace_back([this](){this->work();});
}

void ConnectionModule::work()
{
    // TODO: work in subscription storage and any inter-thread comm
}


} // namespace connection
