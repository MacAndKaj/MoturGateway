/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include "MainLoggerImpl.hpp"

#include "InitializationException.hpp"

#include <spdlog/async.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#ifdef MOTUR_DEBUG
#include <iostream>
#include <mutex>
#endif

namespace common::log::impl
{
#ifdef MOTUR_DEBUG
std::mutex log_mutex;
#endif


MainLoggerImpl::MainLoggerImpl(const std::string& component_name)
    : m_logger_name(std::string(m_logger_name_prefix) + "/" + component_name)
{
    try
    {
        m_logger = spdlog::basic_logger_mt<spdlog::async_factory>(m_logger_name, std::string(m_log_file_path));
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        throw common::exceptions::InitializationException("Main Logger initialization error: " + std::string(ex.what()));
    }
}

MainLoggerImpl::~MainLoggerImpl()
{
    m_logger->flush();
    m_logger.reset();
    spdlog::drop(m_logger_name);
}

void MainLoggerImpl::info(const std::string &str)
{
#ifdef MOTUR_DEBUG
    std::lock_guard<std::mutex> lock(log_mutex);
    std::cout << "[INFO] " << str << std::endl;
#endif
    m_logger->info(str);
}

void MainLoggerImpl::warn(const std::string &str)
{
#ifdef MOTUR_DEBUG
    std::lock_guard<std::mutex> lock(log_mutex);
    std::cout << "[WARN] " << str << std::endl;
#endif
    m_logger->warn(str);
}

void MainLoggerImpl::err(const std::string &str)
{
#ifdef MOTUR_DEBUG
    std::lock_guard<std::mutex> lock(log_mutex);
    std::cout << "[ERR] " << str << std::endl;
#endif
    m_logger->error(str);
}

} // namespace common::log::impl
