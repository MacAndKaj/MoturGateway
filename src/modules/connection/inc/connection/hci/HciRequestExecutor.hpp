/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_HCI_HCIREQUESTEXECUTOR_HPP_
#define CONNECTION_HCI_HCIREQUESTEXECUTOR_HPP_

#include <connection/hci/handlers/IReqHandler.hpp>
#include <connection/utils/IConnectionContext.hpp>

#include <memory>
#include "IRequestsExecutionQueue.hpp"

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
    void executeRequest(std::shared_ptr<defs::HciCommand> cmd, unsigned int req_id);


private:
    std::unique_ptr<IHciSocket> m_requests_socket;
    ISubscriptionsStorage& m_subscriptions_storage;
    common::log::ILogger& m_logger;
    std::map<std::uint16_t, std::shared_ptr<handlers::IReqHandler>> m_handlers;
    std::unique_ptr<IRequestsExecutionQueue> m_execution_queue;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_HCIREQUESTEXECUTOR_HPP_
