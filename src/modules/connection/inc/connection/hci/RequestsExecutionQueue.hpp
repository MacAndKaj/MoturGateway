/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_REQUESTSEXECUTIONQUEUE_HPP
#define CONNECTION_HCI_REQUESTSEXECUTIONQUEUE_HPP

#include <connection/hci/IRequestsExecutionQueue.hpp>

namespace defs
{
class HciCommand;
}

namespace connection::hci
{

class RequestsExecutionQueue : public IRequestsExecutionQueue
{
public:
    virtual ~RequestsExecutionQueue() = default;

    bool empty() const override;

    void add(std::shared_ptr<defs::HciCommand> cmd, unsigned int req_id) override;
    defs::HciCommand& first() const override;

    unsigned int pop() override;

private:
    using Request = std::shared_ptr<defs::HciCommand>;
    using RequestId = unsigned int;

    std::deque<std::pair<Request, RequestId>> m_queue;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_REQUESTSEXECUTIONQUEUE_HPP
