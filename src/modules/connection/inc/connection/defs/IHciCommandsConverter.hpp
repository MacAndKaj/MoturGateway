/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_DEFS_IHCICOMMANDSCONVERTER_HPP_
#define CONNECTION_DEFS_IHCICOMMANDSCONVERTER_HPP_

#include <any>
#include <memory>

namespace connection::defs
{

class HciCommand;

struct ConvertedValueAndPtr
{
    ConvertedValueAndPtr() = delete;
    ConvertedValueAndPtr(std::any&& v, void* p) : value(std::move(v)) , ptr(p){}
    std::any value;
    void* ptr;
};

class IHciCommandsConverter
{
public:
    virtual ~IHciCommandsConverter() = default;
    virtual std::shared_ptr<ConvertedValueAndPtr> getCommandParametersStorage(const HciCommand& cmd) const = 0;
    virtual std::shared_ptr<ConvertedValueAndPtr> getReturnParametersStorage(const HciCommand& cmd) const = 0;
};

} // namespace connection::defs

#endif // CONNECTION_DEFS_IHCICOMMANDSCONVERTER_HPP_
