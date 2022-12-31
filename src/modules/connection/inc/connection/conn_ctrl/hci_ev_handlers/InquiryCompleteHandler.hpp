/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_CONN_CTRL_HCI_EV_HANDLERS_INQUIRYCOMPLETEHANDLER_HPP_
#define CONNECTION_CONN_CTRL_HCI_EV_HANDLERS_INQUIRYCOMPLETEHANDLER_HPP_

#include <log/ILogger.hpp>
#include <connection/defs/HciTypes.hpp>
#include <connection/utils/IConnectionContext.hpp>

namespace connection::conn_ctrl::hci_event_handlers
{

class InquiryCompleteHandler
{
public:
    InquiryCompleteHandler(utils::IConnectionContext& context, defs::HciEvent ev);
    //TODO: add method to get name of handler
    void operator()();

private:
    const defs::HciEvent m_event;
    common::log::ILogger& m_logger;
};

} // namespace connection::conn_ctrl::hci_event_handlers

#endif // CONNECTION_CONN_CTRL_HCI_EV_HANDLERS_INQUIRYCOMPLETEHANDLER_HPP_
