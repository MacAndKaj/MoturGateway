/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_ISUBSCRIPTIONSSTORAGE_HPP
#define CONNECTION_HCI_ISUBSCRIPTIONSSTORAGE_HPP

#include <connection/defs/HciTypes.hpp>

#include <connection/hci/SubscriptionGuard.hpp>

#include <functional>
#include <memory>

namespace connection::hci
{

class ISubscriptionsStorage
{
public:
    using Callback = std::function<void(const defs::HciEvent&)>;

    virtual ~ISubscriptionsStorage() = default;
    virtual std::shared_ptr<SubscriptionGuard> subscribe(defs::HciEventName event_name, const Callback& callback) = 0;
    virtual void notifyAll(const defs::HciEvent& event) const = 0;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_ISUBSCRIPTIONSSTORAGE_HPP
