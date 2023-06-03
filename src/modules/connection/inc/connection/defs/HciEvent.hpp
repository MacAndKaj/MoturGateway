/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_DEFS_HCIEVENT_HPP_
#define CONNECTION_DEFS_HCIEVENT_HPP_

#include <connection/defs/BtDeviceAddress.hpp>
#include <connection/defs/HciCommon.hpp>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>

#include <variant>
#include <map>
#include <cstdint>

namespace connection::defs
{

enum class HciEventName
{
    InquiryComplete = EVT_INQUIRY_COMPLETE,                                 // 0x01
    InquiryResult = EVT_INQUIRY_RESULT,                                     // 0x02
    ConnectionComplete = EVT_CONN_COMPLETE,                                 // 0x03
    ConnectionRequest = EVT_CONN_REQUEST,                                   // 0x04
    DisconnectionComplete = EVT_DISCONN_COMPLETE,                           // 0x05
    AuthenticationComplete = EVT_AUTH_COMPLETE,                             // 0x06
    RemoteNameReqComplete = EVT_REMOTE_NAME_REQ_COMPLETE,                   // 0x07
    EncryptionChange = EVT_ENCRYPT_CHANGE,                                  // 0x08
    ChangeConnectionLinkKeyComplete = EVT_CHANGE_CONN_LINK_KEY_COMPLETE,    // 0x09
    LinkKeyTypeChanged = EVT_MASTER_LINK_KEY_COMPLETE,                      // 0x0A
    ReadRemoteFeaturesComplete = EVT_READ_REMOTE_FEATURES_COMPLETE,         // 0x0B
    ReadRemoteVersionComplete = EVT_READ_REMOTE_VERSION_COMPLETE,           // 0x0C
    QosSetupComplete = EVT_QOS_SETUP_COMPLETE,                              // 0x0D
    CommandComplete = EVT_CMD_COMPLETE,                                     // 0x0E
    CommandStatus = EVT_CMD_STATUS,                                         // 0x0F
//    EVT_HARDWARE_ERROR
//    EVT_FLUSH_OCCURRED
//    EVT_ROLE_CHANGE
//    EVT_NUM_COMP_PKTS
//    EVT_MODE_CHANGE
//    EVT_RETURN_LINK_KEYS
//    EVT_PIN_CODE_REQ
//    EVT_LINK_KEY_REQ
//    EVT_LINK_KEY_NOTIFY
//    EVT_LOOPBACK_COMMAND
//    EVT_DATA_BUFFER_OVERFLOW
//    EVT_MAX_SLOTS_CHANGE
//    EVT_READ_CLOCK_OFFSET_COMPLETE
//    EVT_CONN_PTYPE_CHANGED
//    EVT_QOS_VIOLATION
//    EVT_PSCAN_REP_MODE_CHANGE
};

const std::map<HciEventName, std::string> hci_events_names = {
    {HciEventName::InquiryComplete,    "InquiryComplete"},
    {HciEventName::InquiryResult,      "InquiryResult"},
    {HciEventName::ConnectionComplete, "ConnectionComplete"},
    {HciEventName::ConnectionRequest,  "ConnectionRequest"},
};

const std::map<Status, std::string> statuses_names = {
    {Status::NoError,                     "NoError"},
    {Status::UnknownHciCommand,           "UnknownHciCommand"},
    {Status::UnknownConnectionIdentifier, "UnknownConnectionIdentifier"},
    {Status::HardwareFailure,             "HardwareFailure"},
    {Status::PageTimout,                  "PageTimout"},
    {Status::AuthenticationFailure,        "AuthenticationFailure"},
};

struct InquiryCompleteParameters
{
    Status status;
};


struct InquiryResultParameters
{
    BtDeviceAddress bd_addr;
    std::uint8_t page_scan_repetition_mode;
    std::uint32_t class_of_device;
    std::uint16_t clock_offset;
};

struct ConnectionCompleteParameters
{
    Status status;
    std::uint16_t connetion_handle;
    BtDeviceAddress bd_addr;
    std::uint8_t link_type;
    std::uint8_t encryption_enabled;
};

struct ConnectionRequestParameters
{
    BtDeviceAddress bd_addr;
    std::uint32_t class_of_device;
    std::uint8_t link_type;
};

struct HciEvent
{
    HciEventName name;
    std::variant<
        InquiryCompleteParameters,
        InquiryResultParameters,
        ConnectionCompleteParameters,
        ConnectionRequestParameters
    > parameters;
};

} // namespace connection::defs

#endif // CONNECTION_DEFS_HCIEVENT_HPP_
