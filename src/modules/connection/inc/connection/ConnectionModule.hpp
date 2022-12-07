/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_CONNECTIONMODULE_HPP_
#define CONNECTION_CONNECTIONMODULE_HPP_

#include <connection/workers/IWorker.hpp>

#include <list>
#include <memory>
#include <thread>

namespace connection
{

namespace workers
{
class IWorker;
}

class ConnectionModule
{
public:
    ConnectionModule();

private:
    std::list<std::unique_ptr<workers::IWorker>> m_workers;
    std::list<std::thread> m_threads;
};

} // namespace connection

#endif // CONNECTION_CONNECTIONMODULE_HPP_
