/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include <connection/hci/HciPoller.hpp>

#include <sys/socket.h>

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

}

void HciPoller::setup()
{
    constexpr std::vector<defs::HciEventName> events = {

    };

    m_events_socket->applyEventsFilter(events);
}



} // namespace connection::hci
