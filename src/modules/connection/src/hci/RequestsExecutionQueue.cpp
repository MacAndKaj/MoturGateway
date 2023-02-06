/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/
#include <connection/hci/RequestsExecutionQueue.hpp>

namespace connection::hci
{

bool RequestsExecutionQueue::empty() const
{
    return m_queue.empty();
}

void RequestsExecutionQueue::add(std::shared_ptr<defs::HciCommand> cmd, unsigned int req_id)
{
    m_queue.emplace_back(std::move(cmd), req_id);
}

defs::HciCommand& RequestsExecutionQueue::first() const
{
    return *m_queue.front().first;
}

unsigned int RequestsExecutionQueue::pop()
{
    auto tmp = m_queue.front().second;
    m_queue.pop_front();
    return tmp;
}


} // namespace connection::hci
