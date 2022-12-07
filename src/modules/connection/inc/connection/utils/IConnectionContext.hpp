/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_UTILS_ICONNECTIONCONTEXT_HPP_
#define CONNECTION_UTILS_ICONNECTIONCONTEXT_HPP_

#include <log/MainLogger.hpp>

namespace connection::utils
{

class IConnectionContext
{
public:
    virtual ~IConnectionContext() = default;
    virtual common::log::MainLogger& getMainLogger() const = 0;
};


} // namespace connection::utils

#endif // CONNECTION_UTILS_ICONNECTIONCONTEXT_HPP_
