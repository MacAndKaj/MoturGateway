/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/
#include <connection/hci/HciRequestExecutor.hpp>

namespace connection::hci
{

HciRequestExecutor::HciRequestExecutor(utils::IConnectionContext& context)
    : m_requests_socket(context.getHciObjectsBuilder().buildHciSocket())
    , m_subscriptions_storage(context.getSubscriptionsStorage())
    , m_logger(context.getLogger())
{
    setup();
}

void HciRequestExecutor::work()
{
}

void HciRequestExecutor::setup()
{
}

} // namespace connection::hci
