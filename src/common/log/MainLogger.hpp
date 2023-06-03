/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef MOTURGATEWAY_COMMON_LOG_MAINLOGGER_HPP_
#define MOTURGATEWAY_COMMON_LOG_MAINLOGGER_HPP_

#include "ILogger.hpp"
#include "impl/MainLoggerImpl.hpp"

#include <memory>

namespace common::log
{

class MainLogger : public ILogger
{
public:
    explicit MainLogger(const std::string& name);
    virtual ~MainLogger() = default;

    // TODO: add prefix handling
    void info(const std::string& str) override;
    void warn(const std::string& str) override;
    void err(const std::string& str) override;

private:
    std::unique_ptr<common::log::impl::MainLoggerImpl> m_impl;
};

} // namespace common::log

#endif // MOTURGATEWAY_COMMON_LOG_MAINLOGGER_HPP_
