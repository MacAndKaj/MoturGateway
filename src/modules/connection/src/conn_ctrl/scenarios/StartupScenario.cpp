/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#include <connection/conn_ctrl/scenarios/StartupScenario.hpp>

#include <connection/conn_ctrl/scenarios/ReadBDAddrStep.hpp>

namespace connection::conn_ctrl::scenarios
{

std::unique_ptr<scenarios::IScenario> StartupScenario::create()
{
    return std::unique_ptr<scenarios::IScenario>(new StartupScenario());
}

StartupScenario::StartupScenario()
{
//    m_queue.push_back(ReadBDAddrStep::create());
}

void StartupScenario::run()
{

}

} // namespace connection::conn_ctrl::scenarios
