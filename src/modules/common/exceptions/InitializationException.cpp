/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include "InitializationException.hpp"

namespace common::exceptions
{
InitializationException::InitializationException(const std::string& what)
    : m_what(what)
{
}

const char* InitializationException::what() const noexcept
{
    return m_what.c_str();
}

} // namespace common::exceptions
