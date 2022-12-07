/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_UTILS_CONNECTIONCONTEXT_HPP_
#define CONNECTION_UTILS_CONNECTIONCONTEXT_HPP_

#include <connection/utils/IConnectionContext.hpp>

namespace connection::utils
{

class ConnectionContext : public IConnectionContext
{
public:
    virtual ~ConnectionContext() = default;

    common::log::MainLogger& getMainLogger() const override;

private:
    std::unique_ptr<common::log::MainLogger> m_main_logger;
};


} // namespace connection::utils

#endif // CONNECTION_UTILS_CONNECTIONCONTEXT_HPP_
