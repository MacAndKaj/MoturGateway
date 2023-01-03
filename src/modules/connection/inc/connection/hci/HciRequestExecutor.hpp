/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_HCI_HCIREQUESTEXECUTOR_HPP_
#define CONNECTION_HCI_HCIREQUESTEXECUTOR_HPP_

#include <connection/utils/IConnectionContext.hpp>

#include <memory>

namespace connection::hci
{

class HciRequestExecutor
{
public:
    explicit HciRequestExecutor(utils::IConnectionContext& context);
    virtual ~HciRequestExecutor() = default;

    void work();

protected:
    void setup();

private:
    std::unique_ptr<IHciSocket> m_requests_socket;
    ISubscriptionsStorage& m_subscriptions_storage;
    common::log::ILogger& m_logger;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_HCIREQUESTEXECUTOR_HPP_
