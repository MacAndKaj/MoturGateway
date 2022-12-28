/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/defs/HciEventParser.hpp>

#include <exceptions/UnknownFailureException.hpp>

namespace connection::defs
{

HciEvent HciEventParser::getHciEvent(const char* data)
{
    const hci_event_hdr* hdr;
    const char* ptr;

    hdr = static_cast<const hci_event_hdr*>((void *) (data + 1));
    ptr = data + (1 + HCI_EVENT_HDR_SIZE);

    switch (hdr->evt)
    {
        case EVT_INQUIRY_COMPLETE:
            {
                return convert(*ptr);
            }
            break;
        case EVT_INQUIRY_RESULT:
            {
                auto* ev = static_cast<inquiry_info*>((void*)ptr);
                return convert(*ev);
            }
            break;
        case EVT_CONN_COMPLETE:
            {
                auto* ev = static_cast<evt_conn_complete*>((void*)ptr);
                return convert(*ev);
            }
            break;
        case EVT_CONN_REQUEST:
            {
                auto* ev = static_cast<evt_conn_request*>((void*)ptr);
                return convert(*ev);
            }
            break;
        default:
            {
                throw common::exceptions::UnknownFailureException("Unknown event received: " + std::to_string(hdr->evt));
            }
            break;
    }
}

template<>
HciEvent HciEventParser::convert(const char& ev)
{
    HciEvent ret;
    ret.name = HciEventName::InquiryComplete;

    InquiryCompleteParameters params{
        static_cast<defs::Status>(ev)
    };
    ret.parameters.emplace<InquiryCompleteParameters>(params);

    return ret;
}

template<>
HciEvent HciEventParser::convert(const inquiry_info& ev)
{
    HciEvent ret;
    ret.name = HciEventName::InquiryResult;

    std::uint32_t class_of_device = (ev.dev_class[2] << 16) | (ev.dev_class[1] << 8) | (ev.dev_class[0]);
    InquiryResultParameters params{
        BtDeviceAddress(ev.bdaddr),
        ev.pscan_rep_mode,
        class_of_device,
        ev.clock_offset
    };
    ret.parameters.emplace<InquiryResultParameters>(params);

    return ret;
}

template<>
HciEvent HciEventParser::convert(const evt_conn_request &ev_hdr)
{
    HciEvent ret;
    ret.name = HciEventName::ConnectionRequest;

    std::uint32_t class_of_device = (ev_hdr.dev_class[2] << 16) | (ev_hdr.dev_class[1] << 8) | (ev_hdr.dev_class[0]);
    ConnectionRequestParameters params{
        BtDeviceAddress(ev_hdr.bdaddr),
        class_of_device,
        ev_hdr.link_type
    };
    ret.parameters.emplace<ConnectionRequestParameters>(params);

    return ret;
}

template<>
HciEvent HciEventParser::convert(const evt_conn_complete& ev)
{
    HciEvent ret;
    ret.name = HciEventName::ConnectionComplete;

    ConnectionCompleteParameters params{
        static_cast<Status>(ev.status),
        ev.handle,
        BtDeviceAddress(ev.bdaddr),
        ev.link_type,
        ev.encr_mode
    };
    ret.parameters.emplace<ConnectionCompleteParameters>(params);
    return ret;
}

} // namespace connection::defs
