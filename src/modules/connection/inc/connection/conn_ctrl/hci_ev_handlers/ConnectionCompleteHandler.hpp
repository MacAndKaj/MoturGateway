/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_CONN_CTRL_HCI_EV_HANDLERS_CONNECTIONCOMPLETEHANDLER_HPP_
#define CONNECTION_CONN_CTRL_HCI_EV_HANDLERS_CONNECTIONCOMPLETEHANDLER_HPP_

#include <log/ILogger.hpp>
#include <connection/defs/HciTypes.hpp>


namespace connection::conn_ctrl::hci_event_handlers
{

class ConnectionCompleteHandler
{
public:
    explicit ConnectionCompleteHandler(defs::HciEvent  ev);

    void operator()();


private:
    const defs::HciEvent m_event;
};


} // namespace connection::conn_ctrl::hci_event_handlers

#endif // CONNECTION_CONN_CTRL_HCI_EV_HANDLERS_CONNECTIONCOMPLETEHANDLER_HPP_
