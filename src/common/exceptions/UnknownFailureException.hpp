/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef MOTURGATEWAY_COMMON_EXCEPTIONS_UNKNOWNFAILUREEXCEPTION_HPP_
#define MOTURGATEWAY_COMMON_EXCEPTIONS_UNKNOWNFAILUREEXCEPTION_HPP_

#include "IMoturException.hpp"

#include <string>

namespace common::exceptions
{

class UnknownFailureException : public IMoturException
{
public:
    explicit UnknownFailureException(const std::string& what);
    const char* what() const noexcept override;
private:
    const std::string m_what;
};

} // namespace common::exceptions

#endif // MOTURGATEWAY_COMMON_EXCEPTIONS_UNKNOWNFAILUREEXCEPTION_HPP_
