/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_WORKERS_IWORKER_HPP_
#define CONNECTION_WORKERS_IWORKER_HPP_

namespace connection::workers
{

class IWorker
{
public:
    virtual ~IWorker() = default;
    virtual void work() = 0;
};

} // namespace connection::workers

#endif // CONNECTION_WORKERS_IWORKER_HPP_
