/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/hci/HciSocket.hpp>

#include <connection/defs/HciEventParser.hpp>
#include <exceptions/InitializationException.hpp>
#include <exceptions/ItemNotRetrievedException.hpp>
#include <exceptions/UnknownFailureException.hpp>

#include <sys/poll.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#include <cstring>
#include <unistd.h>

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

defs::HciEvent HciSocket::pollEvent() const
{
    pollfd p{};
    p.fd = m_socket;
    p.events = POLLIN;
    int n = 0;
    constexpr int timeout = 1;
    constexpr int number_of_pollfds = 1;
    if (poll(&p, number_of_pollfds, timeout) < 0)
    {
        throw common::exceptions::UnknownFailureException("Received errno: " + std::string(strerror(errno)));
    }

    if (!(p.revents & POLLIN))
    {
        throw common::exceptions::ItemNotRetrievedException("");
    }

    char buf[HCI_MAX_EVENT_SIZE];
    if (read(m_socket, buf, sizeof(buf)) < 0)
    {
        throw common::exceptions::UnknownFailureException("Received errno: "
                                                          + std::string(strerror(errno))
                                                          + "(" + std::to_string(errno) + ")");
    }

    m_logger.info("[HciSocket] Received event.");
    return defs::HciEventParser::getHciEvent(buf);
}

bool HciSocket::applyEventsFilter(std::vector<defs::HciEventName> events) const
{
    struct hci_filter filter{};
    hci_filter_clear(&filter);

    hci_filter_set_ptype(HCI_EVENT_PKT,  &filter);

    for (auto& e : events)
    {
        hci_filter_set_event(static_cast<int>(e), &filter);
    }

    if (setsockopt(m_socket, SOL_HCI, HCI_FILTER, &filter, sizeof(filter)) < 0)
    {
        m_logger.err("Error when applying filter for socket!");
        return false;
    }

    m_logger.info("[HciSocket] Filters applied successfully.");
    return true;
}

} // namespace connection::hci
