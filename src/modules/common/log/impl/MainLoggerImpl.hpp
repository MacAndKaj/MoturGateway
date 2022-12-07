/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef MOTURGATEWAY_COMMON_LOG_IMPL_MAINLOGGERIMPL_HPP_
#define MOTURGATEWAY_COMMON_LOG_IMPL_MAINLOGGERIMPL_HPP_

#include <memory>
#include <filesystem>
#include <string_view>

namespace spdlog
{
class logger;
}

namespace common::log::impl
{
class MainLoggerImpl
{
public:
    explicit MainLoggerImpl(const std::string& component_name);
    virtual ~MainLoggerImpl();

    void info(const std::string& str);
    void warn(const std::string& str);
    void err(const std::string& str);

private:
    static constexpr std::string_view m_log_file_path{"/tmp/MoturGateway.log"};
    static constexpr std::string_view m_logger_name_prefix{"MoturGwLogger"};

    std::shared_ptr<spdlog::logger> m_logger;
    const std::string m_logger_name;
};

} // namespace log

#endif // MOTURGATEWAY_COMMON_LOG_IMPL_MAINLOGGERIMPL_HPP_
