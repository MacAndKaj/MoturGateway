/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_DEFS_BTDEVICEADDRESS_HPP_
#define CONNECTION_DEFS_BTDEVICEADDRESS_HPP_

#include <bluetooth/bluetooth.h>

#include <string>

namespace connection::defs
{

class BtDeviceAddress
{
public:
    explicit BtDeviceAddress(const bdaddr_t& addr);

    ~BtDeviceAddress() = default;

    std::string toString() const;
    bdaddr_t getRaw() const;

    BtDeviceAddress() = delete;

private:
    bdaddr_t m_addr;
};


} // namespace connection::defs

#endif // CONNECTION_DEFS_BTDEVICEADDRESS_HPP_
