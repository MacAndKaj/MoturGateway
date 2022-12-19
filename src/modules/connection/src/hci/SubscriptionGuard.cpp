/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include <connection/hci/SubscriptionGuard.hpp>

namespace connection::hci
{

SubscriptionGuard::SubscriptionGuard(const std::function<void()>& func)
    : m_fun(func)
{
}

SubscriptionGuard::~SubscriptionGuard()
{
    m_fun();
}

} // namespace connection::hci
