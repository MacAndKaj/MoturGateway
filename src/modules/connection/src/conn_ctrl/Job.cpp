/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/conn_ctrl/Job.hpp>

namespace connection::conn_ctrl
{

Job::Job(const std::function<void()>& fun)
    : m_fun(fun)
{
}

Job::Job(std::unique_ptr<scenarios::IScenario> scenario)
    : m_scenario(std::move(scenario))
    , m_fun{[this](){this->m_scenario->run();}}
{
}

void Job::run()
{
    if (m_fun)
    {
        m_fun();
    }
}

} // namespace connection::conn_ctrl
