/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/defs/BtDeviceAddress.hpp>

namespace connection::defs
{

BtDeviceAddress::BtDeviceAddress(const bdaddr_t& addr)
    : m_addr(addr)
{
}

std::string BtDeviceAddress::toString() const
{
    char ba[19] = { 0 };
    if (ba2str(&m_addr, ba) < 0)
    {
        return {};
    }
    return std::string(ba);
}

bdaddr_t BtDeviceAddress::getRaw() const
{
    return m_addr;
}

} // namespace connection::defs
