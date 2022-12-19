/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#include "TestLogger.hpp"

#include <iostream>

namespace test
{

void TestLogger::info(const std::string& str)
{
    std::cout << "[INFO] " <<  str << std::endl;
}

void TestLogger::warn(const std::string &str)
{
    std::cout << "[WARN] " <<  str << std::endl;
}

void TestLogger::err(const std::string &str)
{
    std::cout << "[ERR] " <<  str << std::endl;
}

} // namespace test
