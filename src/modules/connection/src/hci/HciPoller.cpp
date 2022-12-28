/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include <connection/hci/HciPoller.hpp>

#include <exceptions/ItemNotRetrievedException.hpp>

#include <sys/socket.h>

#include <sstream>

namespace connection::hci
{

HciPoller::HciPoller(utils::IConnectionContext& context)
    : m_events_socket(context.getHciObjectsBuilder().buildHciSocket())
    , m_subscriptions_storage(context.getSubscriptionsStorage())
    , m_logger(context.getLogger())
{
    setup();
}

void HciPoller::work()
{
    try
    {
        defs::HciEvent ev = m_events_socket->pollEvent();
        m_logger.info("Received event: " + defs::hci_events_names.at(ev.name));
        m_subscriptions_storage.notifyAll(ev);
    }
    catch (const common::exceptions::ItemNotRetrievedException&)
    {
        // ignore
    }
}

void HciPoller::setup()
{
    const std::vector<defs::HciEventName> events = {
        defs::HciEventName::InquiryComplete,
        defs::HciEventName::InquiryResult,
        defs::HciEventName::ConnectionComplete,
        defs::HciEventName::ConnectionRequest,
    };

    auto it = events.begin();
    std::stringstream ss;
    ss << "[HciPoller] Subscribing for: " << defs::hci_events_names.at(*it);

    for (++it; it != events.end(); ++it)
    {
        ss << " | " << defs::hci_events_names.at(*it);
    }
    m_logger.info(ss.str());

    m_events_socket->applyEventsFilter(events);
}



} // namespace connection::hci
