/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_CONN_CTRL_JOB_HPP_
#define CONNECTION_CONN_CTRL_JOB_HPP_

#include <functional>

namespace connection::conn_ctrl
{

class Job
{
public:
    //TODO: this class should later handle cases where job is more complex than one synchronous operation
    explicit Job(const std::function<void()>& fun);
    void run();

private:
    std::function<void()> m_fun;
};


} // namespace connection::conn_ctrl

#endif // CONNECTION_CONN_CTRL_JOB_HPP_
