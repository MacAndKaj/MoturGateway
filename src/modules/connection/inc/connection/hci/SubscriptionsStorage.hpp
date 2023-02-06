/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_SUBSCRIPTIONSSTORAGE_HPP
#define CONNECTION_HCI_SUBSCRIPTIONSSTORAGE_HPP

#include <connection/hci/ISubscriptionsStorage.hpp>

#include <log/ILogger.hpp>

#include <map>
#include <list>

namespace connection::hci
{

// TODO: move to utils
class SubscriptionsStorage : public ISubscriptionsStorage
{
public:
    explicit SubscriptionsStorage(common::log::ILogger& logger);
    virtual ~SubscriptionsStorage() = default;

    void request(std::shared_ptr<defs::HciCommand> cmd, const SyncCallback& callback) override;
    std::shared_ptr<SubscriptionGuard> subscribe(defs::HciEventName event_name, const AsyncCallback& callback);

    void registerRequestExecutor(uint16_t command_opcode, RequestExecutor executor) override;

    void notifyAll(const defs::HciEvent& event) const;

protected:
    void removeSubscription(defs::HciEventName event_name, int id);
    struct AsyncSubscription
    {
        AsyncCallback callback;
        unsigned int id;
    };

    void executeResponse(unsigned int id, std::shared_ptr<defs::HciCommand> cmd);

private:
    std::map<defs::HciEventName, int> m_event_counters;
    std::map<defs::HciEventName, std::vector<AsyncSubscription>> m_events_subscriptions;


    unsigned int m_requests_counter{0};
    std::map<unsigned int, SyncCallback> m_commands_callbacks;
    std::map<std::uint16_t, RequestExecutor> m_requests_executors;


    common::log::ILogger& m_logger;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_SUBSCRIPTIONSSTORAGE_HPP
