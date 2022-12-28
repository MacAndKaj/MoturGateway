#include "UnknownFailureException.hpp"

namespace common::exceptions
{

UnknownFailureException::UnknownFailureException(const std::string& what)
    : m_what("[UnknownFailureException]" + what)
{
}

const char* UnknownFailureException::what() const noexcept
{
    return m_what.c_str();
}

} // namespace common::exceptions
