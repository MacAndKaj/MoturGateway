/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_SUBSCRIPTIONSSTORAGE_HPP
#define CONNECTION_HCI_SUBSCRIPTIONSSTORAGE_HPP

#include <connection/hci/ISubscriptionsStorage.hpp>

#include <log/ILogger.hpp>

#include <map>

namespace connection::hci
{

class SubscriptionsStorage : public ISubscriptionsStorage
{
public:
    explicit SubscriptionsStorage(common::log::ILogger& logger);
    virtual ~SubscriptionsStorage() = default;

    std::shared_ptr<SubscriptionGuard> subscribe(defs::HciEventName event_name, const Callback& callback);
    void notifyAll(const defs::HciEvent& event) const;

protected:
    void removeSubscription(defs::HciEventName event_name, int id);
    struct Subscription
    {
        // std::function<bool(const defs::HciEvent&)> filter;
        std::function<void(const defs::HciEvent&)> callback;
        unsigned int id;
    };

private:
    std::map<defs::HciEventName, int> m_counters_map;
    std::map<defs::HciEventName, std::vector<Subscription>> m_subscriptions_map;
    common::log::ILogger& m_logger;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_SUBSCRIPTIONSSTORAGE_HPP
