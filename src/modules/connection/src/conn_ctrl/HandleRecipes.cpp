/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/conn_ctrl/HandleRecipes.hpp>

#include <connection/conn_ctrl/hci_ev_handlers/ConnectionCompleteHandler.hpp>
#include <connection/conn_ctrl/hci_ev_handlers/ConnectionRequestHandler.hpp>
#include <connection/conn_ctrl/hci_ev_handlers/InquiryCompleteHandler.hpp>


namespace connection::conn_ctrl
{

HandleRecipes::HandleRecipes(utils::IConnectionContext& context)
    : m_context(context)
{
}

std::function<void()> HandleRecipes::get(const defs::HciEvent& ev)
{
    switch (ev.name)
    {
        case defs::HciEventName::ConnectionComplete:
            return hci_event_handlers::ConnectionCompleteHandler(m_context, ev);
        case defs::HciEventName::InquiryComplete:
            return hci_event_handlers::InquiryCompleteHandler(m_context, ev);
        case defs::HciEventName::ConnectionRequest:
            return hci_event_handlers::ConnectionRequestHandler(m_context, ev);
        case defs::HciEventName::InquiryResult:
            break;
        case defs::HciEventName::DisconnectionComplete:
            break;
        case defs::HciEventName::AuthenticationComplete:
            break;
        case defs::HciEventName::RemoteNameReqComplete:
            break;
        case defs::HciEventName::EncryptionChange:
            break;
        case defs::HciEventName::ChangeConnectionLinkKeyComplete:
            break;
        case defs::HciEventName::LinkKeyTypeChanged:
            break;
        case defs::HciEventName::ReadRemoteFeaturesComplete:
            break;
        case defs::HciEventName::ReadRemoteVersionComplete:
            break;
        case defs::HciEventName::QosSetupComplete:
            break;
        case defs::HciEventName::CommandComplete:
            break;
        case defs::HciEventName::CommandStatus:
            break;
    }
    return {};
}

} // namespace connection::conn_ctrl
