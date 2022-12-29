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

void Job::run()
{
    if (m_fun)
    {
        m_fun();
    }
}

} // namespace connection::conn_ctrl
