/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef TEST_MOCKS_ICONNECTIONCONTEXTMOCK_HPP_
#define TEST_MOCKS_ICONNECTIONCONTEXTMOCK_HPP_

#include <connection/utils/IConnectionContext.hpp>

#include <log/MainLogger.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace test::mocks
{

class IConnectionContextMock : public connection::utils::IConnectionContext
{
public:
    MOCK_CONST_METHOD0(getMainLogger, common::log::MainLogger&());
};

} // namespace test::mocks

#endif // TEST_MOCKS_ICONNECTIONCONTEXTMOCK_HPP_

