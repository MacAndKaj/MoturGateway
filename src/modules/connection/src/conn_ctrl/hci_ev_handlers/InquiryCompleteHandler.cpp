/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/conn_ctrl/hci_ev_handlers/InquiryCompleteHandler.hpp>

#include <exceptions/InitializationException.hpp>

#include <utility>

namespace connection::conn_ctrl::hci_event_handlers
{

InquiryCompleteHandler::InquiryCompleteHandler(utils::IConnectionContext& context, defs::HciEvent ev)
    : m_event(std::move(ev))
    , m_logger(context.getLogger())
{
    if (not std::holds_alternative<defs::InquiryCompleteParameters>(ev.parameters))
    {
        throw common::exceptions::InitializationException("[InquiryCompleteHandler] Incorrect event received.");
    }
}

void InquiryCompleteHandler::operator()()
{
    auto params = get<defs::InquiryCompleteParameters>(m_event.parameters);

    m_logger.info("[InquiryCompleteHandler] Status: " + defs::statuses_names.at(params.status));
}

}

// namespace connection::conn_ctrl::hci_ev_handlers
