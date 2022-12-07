/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/ConnectionModule.hpp>

#include <connection/workers/HciAsyncEventsDispatcher.hpp>

namespace connection
{

ConnectionModule::ConnectionModule()
{
    m_workers.push_back(std::make_unique<workers::HciAsyncEventsDispatcher>());
}

} // namespace connection
