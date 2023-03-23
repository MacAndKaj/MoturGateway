/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#include <connection/conn_ctrl/scenarios/ReadBDAddrStep.hpp>

namespace connection::conn_ctrl::scenarios
{

std::unique_ptr<IStep> ReadBDAddrStep::create()
{
    return std::unique_ptr<ReadBDAddrStep>(new ReadBDAddrStep);
}

void ReadBDAddrStep::execute()
{

}

} // namespace connection::conn_ctrl::scenarios
