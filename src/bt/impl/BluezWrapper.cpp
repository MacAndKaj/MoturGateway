/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include <bt/impl/BluezWrapper.hpp>

#include <exceptions/InitializationException.hpp>

#include <bluetooth/hci_lib.h>
#include <sys/socket.h>

#include <iostream>
#include <unistd.h>

namespace bt::impl
{
    BluezWrapper::BluezWrapper()
    {
        m_bluetoothAdapterDeviceId = hci_get_route(NULL);
        if (m_bluetoothAdapterDeviceId < 0)
        {
            throw exceptions::InitializationException("Incorrect device ID from hci_get_route.");
        }


        m_btAdapterSocket = hci_open_dev(m_bluetoothAdapterDeviceId);
        if (m_btAdapterSocket < 0)
        {
            auto msg = "Failed while opening socket with ID:" + std::to_string(m_bluetoothAdapterDeviceId);
            throw exceptions::InitializationException(msg.c_str());
        }
    }

    BluezWrapper::~BluezWrapper()
    {
        close(m_btAdapterSocket);
    }

    std::vector<DeviceInfo> BluezWrapper::scanAvailableDevices()
    {
        std::vector<DeviceInfo> ret;
        constexpr int maxPollingTries = 8;
        constexpr long flags = IREQ_CACHE_FLUSH;
        int num_rsp = hci_inquiry(m_bluetoothAdapterDeviceId,
                                  maxPollingTries,
                                  s_m_maxDevicesToFind, NULL,
                                  m_inquiryInfoArray.data(), flags);


        if (num_rsp < 0)
        {
            std::cerr << "Error occured during hci_inquiry" << std::endl;
        }

        ret.reserve(num_rsp);

        char addr[19] = { 0 };
        char name[248] = { 0 };
        for (int i = 0; i < num_rsp; ++i)
        {
            ba2str(&m_inquiryInfoArray[i]->bdaddr, addr);
            memset(name, 0, sizeof(name));
            if (hci_read_remote_name(m_btAdapterSocket, &m_inquiryInfoArray[i]->bdaddr, sizeof(name),
                name, 0) < 0)
            {
                ret.push_back({.address=addr, .name="UNKNOWN"});
            }
        }

        return std::move(ret);
    }

    void BluezWrapper::openSocket()
    {
        int btSocket = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    }
} // namespace bt::impl
