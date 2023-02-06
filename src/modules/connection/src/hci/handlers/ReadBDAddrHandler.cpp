/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/


#include "connection/hci/handlers/ReadBDAddrHandler.hpp"

#include <connection/defs/HciCommand.hpp>

namespace connection::hci::handlers
{

std::pair<std::uint16_t, std::shared_ptr<IReqHandler>> ReadBDAddrHandler::create()
{
    return std::make_pair(
            reqId(),
            std::make_shared<ReadBDAddrHandler>()
        );
}

std::uint16_t handlers::ReadBDAddrHandler::reqId()
{
    return defs::opcode(defs::InformationalParameters, defs::HciReadBDAddr);
}

void ReadBDAddrHandler::run(defs::HciCommand& cmd)
{

}


} // namespace connection::hci::handlers
