/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/
#include "IncorrectValueException.hpp"

namespace common::exceptions
{

IncorrectValueException::IncorrectValueException(const std::string& what)
    : m_what("[IncorrectValueException]" + what)
{
}

const char* IncorrectValueException::what() const noexcept
{
    return m_what.c_str();
}

} // namespace common::exceptions
