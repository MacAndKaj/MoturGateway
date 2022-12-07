/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_WORKERS_HCIASYNCEVENTSDISPATCHER_HPP_
#define CONNECTION_WORKERS_HCIASYNCEVENTSDISPATCHER_HPP_

#include <connection/workers/IWorker.hpp>

namespace connection::workers
{

class HciAsyncEventsDispatcher : public IWorker
{
public:
	HciAsyncEventsDispatcher() = default;
	virtual ~HciAsyncEventsDispatcher() = default;

    void work() override;
};

} // namespace connection::workers

#endif // CONNECTION_WORKERS_HCIASYNCEVENTSDISPATCHER_HPP_
