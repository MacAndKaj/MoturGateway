/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include <connection/workers/HciAsyncEventsDispatcher.hpp>

#include <connection/hci_async/SubscriptionsStorage.hpp>

#include <iostream>

namespace connection::workers
{

void HciAsyncEventsDispatcher::work()
{
    hci_async::SubscriptionsStorage temp;
    std::cout << "Working" << std::endl;
}

} // namespace connection::workers
