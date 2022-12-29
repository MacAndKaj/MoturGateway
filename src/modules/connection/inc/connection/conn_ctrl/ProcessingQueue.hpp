/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_CONN_CTRL_PROCESSINGQUEUE_HPP_
#define CONNECTION_CONN_CTRL_PROCESSINGQUEUE_HPP_

#include <log/ILogger.hpp>
#include <connection/conn_ctrl/IProcessingQueue.hpp>
#include <connection/utils/IConnectionContext.hpp>

#include <deque>
#include <mutex>

namespace connection::conn_ctrl
{

class ProcessingQueue : public IProcessingQueue
{
public:
    explicit ProcessingQueue(utils::IConnectionContext& context);

    void evaluate() override;
    void addJob(std::unique_ptr<Job> ptr) override;

private:
    std::mutex m_mutex;
    std::deque<std::unique_ptr<Job>> m_jobs_queue;
    common::log::ILogger& m_logger;
};


} // namespace connection::conn_ctrl

#endif // CONNECTION_CONN_CTRL_PROCESSINGQUEUE_HPP_
