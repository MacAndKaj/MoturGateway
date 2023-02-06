/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/
#include <connection/defs/HciReturnParametersConverter.hpp>

#include <exceptions/IncorrectValueException.hpp>
#include <exceptions/UnknownFailureException.hpp>

namespace connection::defs
{

HciReturnParametersConverter::HciReturnParametersConverter()
{
    init();
}

void HciReturnParametersConverter::init()
{
    m_converters[HciReadBDAddr] = [this](auto p) { return convertReturnParameters<read_bd_addr_rp>(p); };
}

ReturnParametersVariant HciReturnParametersConverter::convert(const std::shared_ptr<hci_request>& req)
{
    const auto opcode = cmd_opcode_pack(req->ogf, req->ocf);
    auto converter_it = m_converters.find(opcode);

    if (converter_it == m_converters.end())
    {
        throw common::exceptions::IncorrectValueException(
            "[HciReturnParametersConverter] Return params converter not provided for "
            "OGF: " + std::to_string(req->ogf) + " OCF: " + std::to_string(req->ocf));
    }
    return (converter_it->second)(req);
}

template<>
ReturnParametersVariant HciReturnParametersConverter::convertReturnParameters<read_bd_addr_rp>(
    const std::shared_ptr<hci_request>& req)
{
    if (req->rparam == nullptr)
    {
        throw common::exceptions::UnknownFailureException(
            "[HciReturnParametersConverter] Unexpected nullptr in req->rparam");
    }

    auto* rp = static_cast<read_bd_addr_rp*>(req->rparam);

    return HciReadBDAddrReturnParameters{
        static_cast<Status>(rp->status),
        BtDeviceAddress(rp->bdaddr)
    };
}


} // namespace connection::defs

