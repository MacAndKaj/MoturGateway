/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#ifndef TEST_TESTLOGGER_HPP_
#define TEST_TESTLOGGER_HPP_

#include <log/ILogger.hpp>

namespace test
{

class TestLogger : public common::log::ILogger
{
public:
    TestLogger() = default;

    void info(const std::string &str) override;
    void warn(const std::string &str) override;
    void err(const std::string &str) override;
};

} // namespace test

#endif // TEST_TESTLOGGER_HPP_
