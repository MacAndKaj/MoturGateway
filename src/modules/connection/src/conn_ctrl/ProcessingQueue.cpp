/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/conn_ctrl/ProcessingQueue.hpp>

namespace connection::conn_ctrl
{

ProcessingQueue::ProcessingQueue(utils::IConnectionContext& context)
    : m_logger(context.getLogger())
{
}

void ProcessingQueue::evaluate()
{
    if (m_jobs_queue.empty())
    {
        return;
    }

    std::unique_ptr<Job> job_to_run;

    {
        std::lock_guard<std::mutex> lock(m_mutex);
        job_to_run = std::move(m_jobs_queue.back());
        m_jobs_queue.pop_back();
    }

    if (job_to_run)
    {
        m_logger.info("[ProcessingQueue] Starting next job");
        job_to_run->run();
    }
}

void ProcessingQueue::addJob(std::unique_ptr<Job> job)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_jobs_queue.push_back(std::move(job));
    m_logger.info("[ProcessingQueue] New job added to queue.");
}

} // namespace connection::conn_ctrl
