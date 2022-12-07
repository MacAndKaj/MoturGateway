/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include "MainLogger.hpp"

#include "impl/MainLoggerImpl.hpp"

namespace common::log
{

MainLogger::MainLogger(const std::string& name)
    : m_impl(std::make_unique<common::log::impl::MainLoggerImpl>(name))
{
    info("Logger initialized successfully");
}

void MainLogger::info(const std::string &str)
{
    m_impl->info(str);
}

void MainLogger::warn(const std::string &str)
{
    m_impl->warn(str);
}

void MainLogger::err(const std::string &str)
{
    m_impl->err(str);
}

} // namespace common::log
