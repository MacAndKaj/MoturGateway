/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_WORKERS_HCIASYNCEVENTSDISPATCHER_HPP_
#define CONNECTION_WORKERS_HCIASYNCEVENTSDISPATCHER_HPP_

#include <connection/workers/IWorker.hpp>

#include <connection/hci/ISubscriptionsStorage.hpp>
#include <connection/hci/IHciObjectsBuilder.hpp>

#include <atomic>
#include <string>

namespace connection::workers
{

class HciAsyncEventsDispatcher : public IWorker
{
public:
    HciAsyncEventsDispatcher(std::shared_ptr<hci::ISubscriptionsStorage> subscriptions_storage,
                             std::shared_ptr<hci::IHciObjectsBuilder> hci_objects_builder);
    HciAsyncEventsDispatcher() = delete;
	virtual ~HciAsyncEventsDispatcher() = default;

    void run() override;

protected:
    void forceStop();

private:
    std::shared_ptr<hci::ISubscriptionsStorage> m_subscriptions_storage;
    std::shared_ptr<hci::IHciObjectsBuilder> m_hci_objects_builder;
    const std::string M_WORKER_LOGGER_NAME{"HciAsyncEventsDispatcher"};
    std::atomic_bool m_is_running{false};
};

} // namespace connection::workers

#endif // CONNECTION_WORKERS_HCIASYNCEVENTSDISPATCHER_HPP_
