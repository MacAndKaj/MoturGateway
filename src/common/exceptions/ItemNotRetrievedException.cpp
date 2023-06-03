#include "ItemNotRetrievedException.hpp"

namespace common::exceptions
{

ItemNotRetrievedException::ItemNotRetrievedException(const std::string& what)
    : m_what("[ItemNotRetrievedException]" + what)
{
}

const char* ItemNotRetrievedException::what() const noexcept
{
    return m_what.c_str();
}

} // namespace common::exceptions
