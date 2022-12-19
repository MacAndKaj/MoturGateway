/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_HCI_HCIPOLLER_HPP_
#define CONNECTION_HCI_HCIPOLLER_HPP_

#include <connection/utils/IConnectionContext.hpp>

#include <memory>

namespace connection::hci
{

class HciPoller
{
public:
    explicit HciPoller(utils::IConnectionContext& context);
    virtual ~HciPoller() = default;

    void work();

protected:
    void setup();

private:
    std::unique_ptr<IHciSocket> m_events_socket;
    ISubscriptionsStorage& m_subscriptions_storage;
    common::log::ILogger& m_logger;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_HCIPOLLER_HPP_
