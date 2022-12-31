/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/hci/SubscriptionsStorage.hpp>

namespace connection::hci
{

SubscriptionsStorage::SubscriptionsStorage(common::log::ILogger& logger)
    : m_logger(logger)
{
    m_logger.info("[SubscriptionsStorage] Creating subscriptions storage");
}

std::shared_ptr<SubscriptionGuard> SubscriptionsStorage::subscribe(defs::HciEventName event_name, const Callback& callback)
{
    auto counters_iter = m_counters_map.find(event_name);
    if (counters_iter == m_counters_map.end())
    {
        counters_iter = std::get<0>(m_counters_map.emplace(event_name, 0));
    }

    int id = counters_iter->second++;

    m_subscriptions_map[event_name].emplace_back<SubscriptionsStorage::Subscription>({
        callback, static_cast<unsigned int>(id)
    });

    m_logger.info("[SubscriptionsStorage] New subscription created for event " + defs::hci_events_names.at(event_name)
                  + " with ID: " + std::to_string(id));
    return std::make_shared<SubscriptionGuard>([event_name, id, this](){
        this->removeSubscription(event_name, id);
    });
}

void SubscriptionsStorage::removeSubscription(defs::HciEventName event_name, int id)
{
    auto subscriptions_iter = m_subscriptions_map.find(event_name);
    if (subscriptions_iter == m_subscriptions_map.end())
    {
        return;
    }

    auto found_iter = std::find_if(subscriptions_iter->second.begin(), subscriptions_iter->second.end(),
                                   [&](const auto& sub){
                                        return sub.id == id;
                                    });
    if (found_iter == subscriptions_iter->second.end())
    {
        return;
    }

    subscriptions_iter->second.erase(found_iter);
    m_logger.info("[SubscriptionsStorage] Subscription with ID: "+ defs::hci_events_names.at(event_name) + "/"
        + std::to_string(id) + " was removed");
}

void SubscriptionsStorage::notifyAll(const defs::HciEvent& event) const
{
    m_logger.info("[SubscriptionsStorage] Received event: " + defs::hci_events_names.at(event.name));
    auto subscriptions_iter = m_subscriptions_map.find(event.name);
    if (subscriptions_iter == m_subscriptions_map.end())
    {
        return;
    }

    auto& callbacks = subscriptions_iter->second;
    for (auto& [cb, id] : callbacks)
    {
        cb(event);
    }
}

} // namespace connection::hci
