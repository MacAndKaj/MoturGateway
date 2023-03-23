/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_CONN_CTRL_JOB_HPP_
#define CONNECTION_CONN_CTRL_JOB_HPP_

#include <connection/conn_ctrl/scenarios/IScenario.hpp>

#include <functional>
#include <memory>

namespace connection::conn_ctrl
{

class Job
{
public:
    //TODO: this class should later handle cases where job is more complex than one synchronous operation
    explicit Job(const std::function<void()>& fun);
    explicit Job(std::unique_ptr<scenarios::IScenario> scenario);
    void run();

private:
    std::unique_ptr<scenarios::IScenario> m_scenario;
    std::function<void()> m_fun;
};


} // namespace connection::conn_ctrl

#endif // CONNECTION_CONN_CTRL_JOB_HPP_
