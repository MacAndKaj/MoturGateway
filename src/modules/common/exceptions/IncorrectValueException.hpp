/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/
#ifndef MOTURGATEWAY_COMMON_EXCEPTIONS_INCORRECTVALUEEXCEPTION_HPP_
#define MOTURGATEWAY_COMMON_EXCEPTIONS_INCORRECTVALUEEXCEPTION_HPP_

#include "IMoturException.hpp"

#include <string>

namespace common::exceptions
{

class IncorrectValueException : public IMoturException
{
public:
    explicit IncorrectValueException(const std::string& what);
    const char* what() const noexcept override;
private:
    const std::string m_what;
};

} // namespace common::exceptions

#endif // MOTURGATEWAY_COMMON_EXCEPTIONS_INCORRECTVALUEEXCEPTION_HPP_
