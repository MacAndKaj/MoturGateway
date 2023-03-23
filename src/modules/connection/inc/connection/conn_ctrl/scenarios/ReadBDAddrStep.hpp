/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_CONN_CTRL_SCENARIOS_READBDADDRSTEP_HPP_
#define CONNECTION_CONN_CTRL_SCENARIOS_READBDADDRSTEP_HPP_

#include <connection/conn_ctrl/scenarios/IStep.hpp>

#include <memory>

namespace connection::conn_ctrl::scenarios
{

class ReadBDAddrStep : public IStep
{
public:
    static std::unique_ptr<IStep> create();
    virtual ~ReadBDAddrStep() = default;
    void execute() override;
};

} // namespace connection::conn_ctrl::scenarios

#endif //CONNECTION_CONN_CTRL_SCENARIOS_READBDADDRSTEP_HPP_
