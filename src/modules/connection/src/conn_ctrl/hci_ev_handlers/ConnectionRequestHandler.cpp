/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/conn_ctrl/hci_ev_handlers/ConnectionRequestHandler.hpp>

#include <exceptions/InitializationException.hpp>

#include <utility>

namespace connection::conn_ctrl::hci_event_handlers
{

ConnectionRequestHandler::ConnectionRequestHandler(utils::IConnectionContext& context, defs::HciEvent ev)
    : m_event(std::move(ev))
    , m_logger(context.getLogger())
{
    if (not std::holds_alternative<defs::ConnectionRequestParameters>(m_event.parameters))
    {
        throw common::exceptions::InitializationException("[ConnectionRequestHandler] Incorrect event received.");
    }
}

void ConnectionRequestHandler::operator()()
{
    auto params = get<defs::ConnectionRequestParameters>(m_event.parameters);

    m_logger.info("[ConnectionRequestHandler] Connection request from: " + params.bd_addr.toString());
    m_logger.info("[ConnectionRequestHandler] Class of device: " + std::to_string(params.class_of_device));
    m_logger.info("[ConnectionRequestHandler] Link type: " + std::to_string(params.link_type));
}

}

// namespace connection::conn_ctrl::hci_ev_handlers
