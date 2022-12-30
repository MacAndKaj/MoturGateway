/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/conn_ctrl/HandleRecipes.hpp>

#include <connection/conn_ctrl/hci_ev_handlers/ConnectionCompleteHandler.hpp>


namespace connection::conn_ctrl
{

std::function<void()> HandleRecipes::get(const defs::HciEvent& ev)
{
    switch (ev.name)
    {
        case defs::HciEventName::ConnectionComplete:
            return hci_event_handlers::ConnectionCompleteHandler(ev);
        case defs::HciEventName::InquiryComplete:
        case defs::HciEventName::InquiryResult:
        case defs::HciEventName::ConnectionRequest:
            break;
    }
    return {};
}

} // namespace connection::conn_ctrl
