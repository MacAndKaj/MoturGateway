/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/hci/HciSocket.hpp>

#include <exceptions/InitializationException.hpp>

#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#include <memory>
#include <cstring>

namespace connection::hci
{

HciSocket::HciSocket(common::log::ILogger& logger)
    : m_device_id(hci_get_route(NULL))
    , m_logger(logger)
{
    if (m_device_id < 0) 
    {
        throw common::exceptions::InitializationException("[HciSocket] Device ID incorrect.");
    }

    int hci_ctrl_sock = socket(PF_BLUETOOTH, 
        SOCK_RAW | SOCK_CLOEXEC,
        BTPROTO_HCI);
    
    if (hci_ctrl_sock < 0)
    {
        throw common::exceptions::InitializationException("[HciSocket] Socket not created.");
    }

    sockaddr_hci addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.hci_family = AF_BLUETOOTH;
    addr.hci_dev = m_device_id;
    addr.hci_channel = HCI_CHANNEL_RAW;

    if (bind(hci_ctrl_sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        close(hci_ctrl_sock);
        throw common::exceptions::InitializationException("[HciSocket] Bind failure.");
    }
    m_socket = hci_ctrl_sock;
}

HciSocket::~HciSocket()
{
    close(m_socket);
}

void HciSocket::applyEventsFilter(std::vector<defs::HciEventName> events)
{
    struct hci_filter filter;
    hci_filter_clear(&filter);

    hci_filter_set_ptype(HCI_EVENT_PKT,  &filter);

    for (auto& e : events)
    {
        hci_filter_set_event(static_cast<int>(e), &filter);
    }
}

} // namespace connection::hci
