/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include <exceptions/InitializationException.hpp>

namespace exceptions
{
InitializationException::InitializationException(const char* what)
    : m_what(what)
{
}

const char* InitializationException::what() const noexcept
{
    return m_what;
}

}
