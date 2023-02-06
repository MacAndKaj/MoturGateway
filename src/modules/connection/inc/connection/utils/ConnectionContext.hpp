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

    void setSubscriptionsStorage(std::shared_ptr<hci::ISubscriptionsStorage> subscriptions_storage) override;
    hci::ISubscriptionsStorage& getSubscriptionsStorage() const override;

    void setHciObjectsBuilder(std::shared_ptr<hci::IHciObjectsBuilder> hci_objects_builder) override;
    hci::IHciObjectsBuilder& getHciObjectsBuilder() const override;

    void setHciCommandsConverter(std::unique_ptr<defs::IHciCommandsConverter> hci_commands_converter) override;
    defs::IHciCommandsConverter& getHciCommandsConverter() const override;

    void setHciReturnParametersConverter(std::unique_ptr<defs::IHciReturnParametersConverter> converter) override;
    defs::IHciReturnParametersConverter& getHciReturnParametersConverter() const override;

private:
    std::unique_ptr<common::log::ILogger> m_main_logger;
    std::shared_ptr<hci::ISubscriptionsStorage> m_subscriptions_storage;
    std::shared_ptr<hci::IHciObjectsBuilder> m_hci_objects_builder;
    std::unique_ptr<defs::IHciCommandsConverter> m_hci_commands_converter;
    std::unique_ptr<defs::IHciReturnParametersConverter> m_hci_return_parameters_converter;
};


} // namespace connection::utils

#endif // CONNECTION_UTILS_CONNECTIONCONTEXT_HPP_
