/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_ISUBSCRIPTIONSSTORAGE_HPP
#define CONNECTION_HCI_ISUBSCRIPTIONSSTORAGE_HPP

#include <connection/defs/HciEvent.hpp>
#include <connection/hci/SubscriptionGuard.hpp>

#include <functional>
#include <memory>

namespace connection::defs
{
class HciCommand;
class HciEvent;
}

namespace connection::hci
{

class ISubscriptionsStorage
{
public:
    using AsyncCallback = std::function<void(const defs::HciEvent&)>;
    using SyncCallback = std::function<void(std::shared_ptr<defs::HciCommand>)>;
    using RequestExecutor = std::function<void(std::shared_ptr<defs::HciCommand>, unsigned int)>;

    virtual ~ISubscriptionsStorage() = default;

    // --------------------------------- CLIENT METHODS ---------------------------------
    virtual std::shared_ptr<SubscriptionGuard> subscribe(defs::HciEventName event_name, const AsyncCallback& callback) = 0;
    virtual void request(std::shared_ptr<defs::HciCommand> cmd, const SyncCallback& callback) = 0;


    // --------------------------------- SERVER METHODS ---------------------------------
    virtual void registerRequestExecutor(uint16_t command_opcode, RequestExecutor executor) = 0;
    virtual void notifyAll(const defs::HciEvent& event) const = 0;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_ISUBSCRIPTIONSSTORAGE_HPP
