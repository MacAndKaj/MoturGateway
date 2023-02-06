/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_HANDLERS_IREQHANDLER_HPP_
#define CONNECTION_HCI_HANDLERS_IREQHANDLER_HPP_

#include <connection/defs/HciCommand.hpp>

#include <cstdint>

namespace connection::hci::handlers
{

class IReqHandler
{
public:
    virtual ~IReqHandler() = default;
    virtual void run(defs::HciCommand& cmd) = 0;
};

} // namespace connection::hci::handlers

#endif // CONNECTION_HCI_HANDLERS_IREQHANDLER_HPP_
