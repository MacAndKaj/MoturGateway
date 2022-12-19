/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_SUBSCRIPTIONGUARD_HPP
#define CONNECTION_HCI_SUBSCRIPTIONGUARD_HPP

#include <connection/defs/HciTypes.hpp>

#include <functional>

namespace connection::hci
{

class SubscriptionGuard
{
public:
    SubscriptionGuard() = delete;
    SubscriptionGuard(const std::function<void()>& func);
    ~SubscriptionGuard();

private:
    std::function<void()> m_fun;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_SUBSCRIPTIONGUARD_HPP
