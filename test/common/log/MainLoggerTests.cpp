/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include "MainLogger.hpp"

#include <gtest/gtest.h>

#include <spdlog/async.h>
#include <spdlog/spdlog.h>

#include <fstream>

namespace common::log
{

namespace
{
const std::string LOG_PATH{"/tmp/MoturGateway.log"};
}

class MainLoggerTests : public ::testing::Test
{
public:
    virtual void SetUp() override
    {
        spdlog::init_thread_pool(10,10);
    }

    std::unique_ptr<MainLogger> createSut(const std::string name="TEST")
    {
        return std::make_unique<MainLogger>(name);
    }

    virtual void TearDown() override
    {
        if (std::filesystem::exists(LOG_PATH))
        {
            std::filesystem::remove(LOG_PATH);
        }
    }
};

TEST_F(MainLoggerTests, OneThreadUsecase)
{
    auto sut = createSut();
    sut->info("Some log sample");
    sut.reset();
}

TEST_F(MainLoggerTests, MultipleLoggersUsecase)
{
    auto sut1 = createSut("TEST1");
    auto sut2 = createSut("TEST2");
}

TEST_F(MainLoggerTests, MultithreadingUsecase)
{
    auto sut = createSut();
}

} // namespace common::log
