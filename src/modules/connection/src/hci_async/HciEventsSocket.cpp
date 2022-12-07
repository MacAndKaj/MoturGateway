/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/hci_async/HciEventsSocket.hpp>

#include <exceptions/InitializationException.hpp>

#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#include <memory>
#include <cstring>

namespace connection::hci_async
{

HciEventsSocket::HciEventsSocket()
    : m_device_id(hci_get_route(NULL))
{
    if (m_device_id < 0) 
    {
        throw common::exceptions::InitializationException("[HciEventsSocket] Device ID incorrect.");
    }

    int hci_ctrl_sock = socket(PF_BLUETOOTH, 
        SOCK_RAW | SOCK_CLOEXEC,
        BTPROTO_HCI);
    
    if (hci_ctrl_sock < 0)
    {
        throw common::exceptions::InitializationException("[HciEventsSocket] Socket not created.");
    }

    sockaddr_hci addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.hci_family = AF_BLUETOOTH;
    addr.hci_dev = m_device_id;
    addr.hci_channel = HCI_CHANNEL_RAW;

    if (bind(hci_ctrl_sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        close(hci_ctrl_sock);
        throw common::exceptions::InitializationException("[HciEventsSocket] Bind failure.");
    }
    m_socket = hci_ctrl_sock;
}

HciEventsSocket::~HciEventsSocket()
{
    close(m_socket);
}



} // namespace connection::hci_async
