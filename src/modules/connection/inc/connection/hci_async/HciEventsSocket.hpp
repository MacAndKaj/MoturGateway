/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_HCI_ASYNC_HCISOCKET_HPP_
#define CONNECTION_HCI_ASYNC_HCISOCKET_HPP_

namespace connection::hci_async
{

class HciEventsSocket // : public IHciEventsSocket
{
public:
	HciEventsSocket();
	virtual ~HciEventsSocket();

private:
	int m_device_id;
    int m_socket;
};

} // namespace connection::hci_async

#endif // CONNECTION_HCI_ASYNC_HCISOCKET_HPP_
