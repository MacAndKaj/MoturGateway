/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/hci/SubscriptionsStorage.hpp>

#include <connection/defs/HciCommand.hpp>

#include <utility>

namespace connection::hci
{

SubscriptionsStorage::SubscriptionsStorage(common::log::ILogger& logger)
    : m_logger(logger)
{
    m_logger.info("[SubscriptionsStorage] Creating subscriptions storage");
}

std::shared_ptr<SubscriptionGuard> SubscriptionsStorage::subscribe(defs::HciEventName event_name,
                                                                   const AsyncCallback& callback)
{
    auto counters_iter = m_event_counters.find(event_name);
    if (counters_iter == m_event_counters.end())
    {
        counters_iter = std::get<0>(m_event_counters.emplace(event_name, 0));
    }

    int id = counters_iter->second++;

    m_events_subscriptions[event_name].emplace_back<SubscriptionsStorage::AsyncSubscription>({
                                                                                                 callback,
                                                                                                 static_cast<unsigned int>(id)
                                                                                             });

    m_logger.info("[SubscriptionsStorage] New subscription created for event " + defs::hci_events_names.at(event_name)
                  + " with ID: " + std::to_string(id));
    return std::make_shared<SubscriptionGuard>([event_name, id, this]()
                                               {
                                                   this->removeSubscription(event_name, id);
                                               });
}

void SubscriptionsStorage::removeSubscription(defs::HciEventName event_name, int id)
{
    auto subscriptions_iter = m_events_subscriptions.find(event_name);
    if (subscriptions_iter == m_events_subscriptions.end())
    {
        return;
    }

    auto found_iter = std::find_if(subscriptions_iter->second.begin(), subscriptions_iter->second.end(),
                                   [&](const auto& sub)
                                   {
                                       return sub.id == id;
                                   });
    if (found_iter == subscriptions_iter->second.end())
    {
        return;
    }

    subscriptions_iter->second.erase(found_iter);
    m_logger.info("[SubscriptionsStorage] Subscription with ID: " + defs::hci_events_names.at(event_name) + "/"
                  + std::to_string(id) + " was removed");
}

void SubscriptionsStorage::request(std::shared_ptr<defs::HciCommand> cmd, const SyncCallback& callback)
{
    m_logger.info("[SubscriptionsStorage] New request received.");
    auto executor_it = m_requests_executors.find(cmd->getOpcode());
    if (executor_it == m_requests_executors.end())
    {
        m_logger.info("[SubscriptionsStorage] Executor not found, ignoring request.");
        return;
    }

    m_commands_callbacks[m_requests_counter] = callback;
    (executor_it->second)(cmd, m_requests_counter++);
}

void SubscriptionsStorage::notifyAll(const defs::HciEvent& event) const
{
    m_logger.info("[SubscriptionsStorage] Received event: " + defs::hci_events_names.at(event.name));
    auto subscriptions_iter = m_events_subscriptions.find(event.name);
    if (subscriptions_iter == m_events_subscriptions.end())
    {
        return;
    }

    auto& callbacks = subscriptions_iter->second;
    for (auto& [cb, id]: callbacks)
    {
        cb(event);
    }
}

void SubscriptionsStorage::registerRequestExecutor(uint16_t command_opcode,
                                                   ISubscriptionsStorage::RequestExecutor executor)
{
    if (m_requests_executors.find(command_opcode) != m_requests_executors.end())
    {
        m_logger.warn("[SubscriptionsStorage] Overriding subscription!");
    }

    m_requests_executors[command_opcode] = executor;

    m_logger.info(
        "[SubscriptionsStorage] Executor reqgistered for OGF: " + std::to_string(cmd_opcode_ogf(command_opcode)) +
        " | OCF: " + std::to_string(cmd_opcode_ocf(command_opcode)));
}

void SubscriptionsStorage::executeResponse(unsigned int id, std::shared_ptr<defs::HciCommand> cmd)
{
    auto cb = m_commands_callbacks.find(id);
    if (cb != m_commands_callbacks.end())
    {
        (cb->second)(std::move(cmd));
    }
}

} // namespace connection::hci
