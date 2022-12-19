/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_UTILS_CONNECTIONCONTEXT_HPP_
#define CONNECTION_UTILS_CONNECTIONCONTEXT_HPP_

#include <connection/utils/IConnectionContext.hpp>


namespace connection::utils
{

class ConnectionContext : public IConnectionContext
{
public:
    virtual ~ConnectionContext() = default;

    void setLogger(std::unique_ptr<common::log::ILogger> logger) override;
    common::log::ILogger& getLogger() const override;

    void setSubscriptionsStorage(std::unique_ptr<hci::ISubscriptionsStorage> subscriptions_storage) override;
    hci::ISubscriptionsStorage& getSubscriptionsStorage() const override;

    void setHciObjectsBuilder(std::unique_ptr<hci::IHciObjectsBuilder> hci_objects_builder) override;
    hci::IHciObjectsBuilder& getHciObjectsBuilder() const override;

private:
    std::unique_ptr<common::log::ILogger> m_main_logger;
    std::unique_ptr<hci::ISubscriptionsStorage> m_subscriptions_storage;
    std::unique_ptr<hci::IHciObjectsBuilder> m_hci_objects_builder;
};


} // namespace connection::utils

#endif // CONNECTION_UTILS_CONNECTIONCONTEXT_HPP_
