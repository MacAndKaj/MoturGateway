/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */

#ifndef MOTURGATEWAY_BT_IMPL_BLUEZWRAPPER_HPP
#define MOTURGATEWAY_BT_IMPL_BLUEZWRAPPER_HPP

#include <bt/impl/defs.hpp>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>

#include <array>
#include <vector>

namespace bt::impl
{
    class BluezWrapper
    {
    public:
        BluezWrapper();
        virtual ~BluezWrapper();
        std::vector<DeviceInfo> scanAvailableDevices();
        void openSocket();


    private:
        int m_bluetoothAdapterDeviceId;
        int m_btAdapterSocket;
        constexpr static int s_m_maxDevicesToFind{255};
        std::array<inquiry_info*, s_m_maxDevicesToFind> m_inquiryInfoArray;
    };
} //namespace bt::impl

#endif // MOTURGATEWAY_BT_IMPL_BLUEZWRAPPER_HPP
