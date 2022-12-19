/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#ifndef TEST_CONNECTIONTESTBASE_HPP
#define TEST_CONNECTIONTESTBASE_HPP

#include <connection/utils/ConnectionContext.hpp>

namespace test
{

class ConnectionTestBase
{
public:
    ConnectionTestBase();

    connection::utils::ConnectionContext& getContext();

private:
    connection::utils::ConnectionContext m_context;
};

} // namespace test

#endif // TEST_CONNECTIONTESTBASE_HPP
