/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include <connection/utils/ConnectionContext.hpp>

namespace connection::utils
{

void ConnectionContext::setLogger(std::unique_ptr<common::log::ILogger> logger)
{
    m_main_logger = std::move(logger);
}

common::log::ILogger& ConnectionContext::getLogger() const
{
    return *m_main_logger;
}

void ConnectionContext::setSubscriptionsStorage(std::shared_ptr<hci::ISubscriptionsStorage> subscriptions_storage)
{
    m_subscriptions_storage = std::move(subscriptions_storage);
}

hci::ISubscriptionsStorage& ConnectionContext::getSubscriptionsStorage() const
{
    return *m_subscriptions_storage;
}

void ConnectionContext::setHciObjectsBuilder(std::shared_ptr<hci::IHciObjectsBuilder> hci_objects_builder)
{
    m_hci_objects_builder = std::move(hci_objects_builder);
}

hci::IHciObjectsBuilder &ConnectionContext::getHciObjectsBuilder() const
{
    return *m_hci_objects_builder;
}

void ConnectionContext::setHciCommandsConverter(std::unique_ptr<defs::IHciCommandsConverter> hci_commands_converter)
{
    m_hci_commands_converter = std::move(hci_commands_converter);
}

defs::IHciCommandsConverter& ConnectionContext::getHciCommandsConverter() const
{
    return *m_hci_commands_converter;
}

void ConnectionContext::setHciReturnParametersConverter(std::unique_ptr<defs::IHciReturnParametersConverter> converter)
{
    m_hci_return_parameters_converter = std::move(converter);
}

defs::IHciReturnParametersConverter& ConnectionContext::getHciReturnParametersConverter() const
{
    return *m_hci_return_parameters_converter;
}


} // namespace connection::utils
