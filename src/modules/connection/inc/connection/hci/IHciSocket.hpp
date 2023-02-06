/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_IHCISOCKET_HPP_
#define CONNECTION_HCI_IHCISOCKET_HPP_

#include <connection/defs/HciEvent.hpp>

#include <vector>

namespace connection::hci
{

class IHciSocket
{
public:
    virtual ~IHciSocket() = default;
    virtual defs::HciEvent pollEvent() const = 0;
    virtual bool applyEventsFilter(std::vector<defs::HciEventName> events) const = 0;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_IHCISOCKET_HPP_
