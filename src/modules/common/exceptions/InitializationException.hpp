/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef MOTURGATEWAY_COMMON_EXCEPTIONS_INITIALIZATIONEXCEPTION_HPP_
#define MOTURGATEWAY_COMMON_EXCEPTIONS_INITIALIZATIONEXCEPTION_HPP_

#include <exception>
#include <string>

namespace common::exceptions
{

class InitializationException : public std::exception
{
public:
    explicit InitializationException(const std::string& what);
    const char* what() const noexcept override;
private:
    const std::string m_what;
};

} // namespace common::exceptions

#endif // MOTURGATEWAY_COMMON_EXCEPTIONS_INITIALIZATIONEXCEPTION_HPP_
