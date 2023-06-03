/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef MOTURGATEWAY_COMMON_EXCEPTIONS_ITEMNOTRETRIEVEDEXCEPTION_HPP_
#define MOTURGATEWAY_COMMON_EXCEPTIONS_ITEMNOTRETRIEVEDEXCEPTION_HPP_

#include "IMoturException.hpp"

#include <string>

namespace common::exceptions
{

class ItemNotRetrievedException : public IMoturException
{
public:
    explicit ItemNotRetrievedException(const std::string& what);
    const char* what() const noexcept override;
private:
    const std::string m_what;
};

} // namespace common::exceptions

#endif // MOTURGATEWAY_COMMON_EXCEPTIONS_ITEMNOTRETRIEVEDEXCEPTION_HPP_
