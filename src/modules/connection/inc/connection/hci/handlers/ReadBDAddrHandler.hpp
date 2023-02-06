/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_HANDLERS_READBDADDRHANDLER_HPP_
#define CONNECTION_HCI_HANDLERS_READBDADDRHANDLER_HPP_

#include <connection/hci/handlers/IReqHandler.hpp>

#include <memory>

namespace connection::hci::handlers
{

class ReadBDAddrHandler : public IReqHandler
{
public:
    static std::pair<std::uint16_t, std::shared_ptr<IReqHandler>> create();

    virtual ~ReadBDAddrHandler() = default;

    void run(defs::HciCommand& cmd) override;

protected:
    static std::uint16_t reqId();

};

} // namespace connection::hci::handlers

#endif // CONNECTION_HCI_HANDLERS_READBDADDRHANDLER_HPP_
