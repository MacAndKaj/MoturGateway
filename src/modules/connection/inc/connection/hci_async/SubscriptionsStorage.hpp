/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_ASYNC_SUBSCRIPTIONSSTORAGE_HPP
#define CONNECTION_HCI_ASYNC_SUBSCRIPTIONSSTORAGE_HPP

#include <connection/hci_async/ISubscriptionsStorage.hpp>

#include <log/MainLogger.hpp>
#include <connection/utils/IConnectionContext.hpp>

#include <map>

namespace connection::hci_async
{

class SubscriptionsStorage : public ISubscriptionsStorage
{
public:
    explicit SubscriptionsStorage(utils::IConnectionContext& context);
    virtual ~SubscriptionsStorage() = default;

    SubscriptionGuard subscribe(defs::HciEventName event_name, const Callback& callback);
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
    common::log::MainLogger& m_logger;
};

} // namespace connection::hci_async

#endif // CONNECTION_HCI_ASYNC_SUBSCRIPTIONSSTORAGE_HPP
