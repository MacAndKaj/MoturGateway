/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef MOTURGATEWAY_COMMON_LOG_ILOGGER_HPP_
#define MOTURGATEWAY_COMMON_LOG_ILOGGER_HPP_

#include <string>

namespace common::log
{

class ILogger
{
public:
    virtual ~ILogger() = default;

    virtual void info(const std::string& str) = 0;
    virtual void warn(const std::string& str) = 0;
    virtual void err(const std::string& str) = 0;
};

} // namespace common::log

#endif // MOTURGATEWAY_COMMON_LOG_ILOGGER_HPP_
