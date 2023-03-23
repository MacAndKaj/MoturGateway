/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_CONN_CTRL_SCENARIOS_STARTUPSCENARIO_HPP_
#define CONNECTION_CONN_CTRL_SCENARIOS_STARTUPSCENARIO_HPP_

#include <connection/conn_ctrl/scenarios/IStep.hpp>
#include <connection/conn_ctrl/scenarios/IScenario.hpp>

#include <vector>
#include <memory>

namespace connection::conn_ctrl::scenarios
{

class StartupScenario : public IScenario
{
public:
    static std::unique_ptr<scenarios::IScenario> create();

    void run() override;

protected:
    StartupScenario();

private:
    std::vector<std::unique_ptr<IStep>> m_queue;
};

} // namespace connection::conn_ctrl::scenarios

#endif // CONNECTION_CONN_CTRL_SCENARIOS_STARTUPSCENARIO_HPP_
