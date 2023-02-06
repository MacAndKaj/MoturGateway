/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_DEFS_IHCIRETURNPARAMETERSCONVERTER_HPP_
#define CONNECTION_DEFS_IHCIRETURNPARAMETERSCONVERTER_HPP_

#include <connection/defs/HciCommandTypes.hpp>

#include <bluetooth/hci_lib.h>

#include <memory>

namespace connection::defs
{

class IHciReturnParametersConverter
{
public:
    virtual ReturnParametersVariant convert(const std::shared_ptr<hci_request>& req) = 0;
};

} // namespace connection::defs

#endif // CONNECTION_DEFS_IHCIRETURNPARAMETERSCONVERTER_HPP_
