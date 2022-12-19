/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_HCI_HCIEVENTSSOCKET_HPP_
#define CONNECTION_HCI_HCIEVENTSSOCKET_HPP_

#include <connection/hci/IHciSocket.hpp>

#include <log/ILogger.hpp>

namespace connection::hci
{

class HciSocket : public IHciSocket
{
public:
    explicit HciSocket(common::log::ILogger& logger);
    virtual ~HciSocket();

    void applyEventsFilter(std::vector<defs::HciEventName> events);

private:
	int m_device_id;
    int m_socket;
    common::log::ILogger& m_logger;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_HCIEVENTSSOCKET_HPP_
