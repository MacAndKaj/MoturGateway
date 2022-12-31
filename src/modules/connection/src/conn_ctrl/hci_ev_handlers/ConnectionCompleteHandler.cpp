/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/conn_ctrl/hci_ev_handlers/ConnectionCompleteHandler.hpp>

#include <exceptions/InitializationException.hpp>

#include <utility>

namespace connection::conn_ctrl::hci_event_handlers
{

ConnectionCompleteHandler::ConnectionCompleteHandler(utils::IConnectionContext& context, defs::HciEvent ev)
    : m_event(std::move(ev))
    , m_logger(context.getLogger())
{
    if (not std::holds_alternative<defs::ConnectionCompleteParameters>(ev.parameters))
    {
        throw common::exceptions::InitializationException("[ConnectionCompleteHandler] Incorrect event received.");
    }
}

void ConnectionCompleteHandler::operator()()
{
    auto params = get<defs::ConnectionCompleteParameters>(m_event.parameters);

    m_logger.info("[ConnectionCompleteHandler] Status: " + defs::statuses_names.at(params.status));
    m_logger.info("[ConnectionCompleteHandler] Address: " + params.bd_addr.toString());
    m_logger.info("[ConnectionCompleteHandler] Link type: " + std::to_string(params.link_type));
}

}

// namespace connection::conn_ctrl::hci_ev_handlers
