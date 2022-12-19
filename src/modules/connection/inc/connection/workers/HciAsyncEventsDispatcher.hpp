/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_WORKERS_HCIASYNCEVENTSDISPATCHER_HPP_
#define CONNECTION_WORKERS_HCIASYNCEVENTSDISPATCHER_HPP_

#include <connection/workers/IWorker.hpp>

#include <atomic>
#include <string>

namespace connection::workers
{

class HciAsyncEventsDispatcher : public IWorker
{
public:
	HciAsyncEventsDispatcher() = default;
	virtual ~HciAsyncEventsDispatcher() = default;

    void run() override;

protected:
    void forceStop();

private:
    const std::string M_WORKER_LOGGER_NAME{"HciAsyncEventsDispatcher"};
    std::atomic_bool m_is_running{false};
};

} // namespace connection::workers

#endif // CONNECTION_WORKERS_HCIASYNCEVENTSDISPATCHER_HPP_
