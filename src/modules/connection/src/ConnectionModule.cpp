/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/ConnectionModule.hpp>

#include <connection/workers/HciAsyncEventsDispatcher.hpp>

#include <algorithm>

namespace connection
{

ConnectionModule::ConnectionModule()
{
    m_workers.push_back(std::make_unique<workers::HciAsyncEventsDispatcher>());
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
