/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_IREQUESTSEXECUTIONQUEUE_HPP
#define CONNECTION_HCI_IREQUESTSEXECUTIONQUEUE_HPP

#include <memory>
#include <deque>

namespace defs
{
class HciCommand;
}

namespace connection::hci
{

class IRequestsExecutionQueue
{
public:
    virtual ~IRequestsExecutionQueue() = default;

    /// Checks if there are any pending requests.
    /// \return true if queue is empty, false otherwise.
    virtual bool empty() const = 0;

    /// Adds new request to queue with ID.
    /// \param cmd Request to be executed.
    /// \param req_id Request ID in subscription storage.
    virtual void add(std::shared_ptr<defs::HciCommand> cmd, unsigned int req_id) = 0;\

    /// Return reference to first command in the queue
    /// \return
    virtual defs::HciCommand& first() const = 0;

    /// Pops first item from queue and return ID of request.
    /// \return ID of request
    virtual unsigned int pop() = 0;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_IREQUESTSEXECUTIONQUEUE_HPP
