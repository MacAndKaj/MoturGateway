/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_CONN_CTRL_SCENARIOS_ISTEP_HPP_
#define CONNECTION_CONN_CTRL_SCENARIOS_ISTEP_HPP_

namespace connection::conn_ctrl::scenarios
{

class IStep
{
public:
    virtual ~IStep() = default;
    virtual void execute() = 0;
};

} // namespace connection::conn_ctrl::scenarios

#endif //CONNECTION_CONN_CTRL_SCENARIOS_ISTEP_HPP_
