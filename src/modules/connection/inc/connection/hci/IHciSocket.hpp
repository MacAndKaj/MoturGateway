/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_IHCISOCKET_HPP_
#define CONNECTION_HCI_IHCISOCKET_HPP_

#include <connection/defs/HciTypes.hpp>

#include <vector>

namespace connection::hci
{

class IHciSocket
{
public:
    virtual ~IHciSocket() = default;
    virtual void applyEventsFilter(std::vector<defs::HciEventName> events) = 0;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_IHCISOCKET_HPP_
