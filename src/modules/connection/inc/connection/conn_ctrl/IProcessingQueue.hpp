/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_CONN_CTRL_IPROCESSINGQUEUE_HPP_
#define CONNECTION_CONN_CTRL_IPROCESSINGQUEUE_HPP_

#include <connection/conn_ctrl/Job.hpp>

#include <memory>

namespace connection::conn_ctrl
{

class IProcessingQueue
{
public:
    virtual ~IProcessingQueue() = default;
    virtual void evaluate() = 0;
    virtual void addJob(std::unique_ptr<Job>) = 0;
};


} // namespace connection::conn_ctrl

#endif // CONNECTION_CONN_CTRL_IPROCESSINGQUEUE_HPP_
