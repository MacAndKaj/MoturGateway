/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_UTILS_ICONNECTIONCONTEXT_HPP_
#define CONNECTION_UTILS_ICONNECTIONCONTEXT_HPP_

#include <log/ILogger.hpp>
#include <connection/hci/ISubscriptionsStorage.hpp>
#include <connection/hci/IHciObjectsBuilder.hpp>

#include <memory>

namespace connection::utils
{

class IConnectionContext
{
public:
    virtual ~IConnectionContext() = default;

    virtual void setLogger(std::unique_ptr<common::log::ILogger> logger) = 0;
    virtual common::log::ILogger& getLogger() const = 0;

    virtual void setSubscriptionsStorage(std::shared_ptr<hci::ISubscriptionsStorage> subscriptions_storage) = 0;
    virtual hci::ISubscriptionsStorage& getSubscriptionsStorage() const = 0;

    virtual void setHciObjectsBuilder(std::shared_ptr<hci::IHciObjectsBuilder> hci_objects_builder) = 0;
    virtual hci::IHciObjectsBuilder& getHciObjectsBuilder() const = 0;
};


} // namespace connection::utils

#endif // CONNECTION_UTILS_ICONNECTIONCONTEXT_HPP_
