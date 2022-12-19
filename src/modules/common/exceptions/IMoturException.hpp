/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef MOTURGATEWAY_COMMON_EXCEPTIONS_IMOTUREXCEPTION_HPP_
#define MOTURGATEWAY_COMMON_EXCEPTIONS_IMOTUREXCEPTION_HPP_

namespace common::exceptions
{

class IMoturException
{
public:
    virtual ~IMoturException() = default;
    virtual const char* what() const noexcept = 0;
};

} // namespace common::exceptions

#endif // MOTURGATEWAY_COMMON_EXCEPTIONS_IMOTUREXCEPTION_HPP_
