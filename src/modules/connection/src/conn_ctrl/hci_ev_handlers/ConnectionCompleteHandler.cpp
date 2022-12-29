/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/conn_ctrl/hci_ev_handlers/ConnectionCompleteHandler.hpp>
#include <utility>

namespace connection::conn_ctrl::hci_event_handlers
{

ConnectionCompleteHandler::ConnectionCompleteHandler(connection::defs::HciEvent  ev)
    : m_event(std::move(ev))
{
}

void ConnectionCompleteHandler::operator()()
{

}

}

// namespace connection::conn_ctrl::hci_ev_handlers
