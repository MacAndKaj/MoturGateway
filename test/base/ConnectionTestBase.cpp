/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#include "ConnectionTestBase.hpp"

#include "TestLogger.hpp"

namespace test
{

ConnectionTestBase::ConnectionTestBase()
{
    m_context.setLogger(std::make_unique<TestLogger>());
}

connection::utils::ConnectionContext &ConnectionTestBase::getContext()
{
    return m_context;
}

} // namespace test
