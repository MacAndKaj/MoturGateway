/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#include <connection/defs/HciCommandsConverter.hpp>

#include <connection/defs/HciCommand.hpp>
#include <exceptions/UnknownFailureException.hpp>
#include <exceptions/IncorrectValueException.hpp>

#include <bluetooth/hci.h>

namespace connection::defs
{

HciCommandsConverter::HciCommandsConverter()
{
    init();
}

void HciCommandsConverter::init()
{
    m_cp_converters[HciReadBDAddr] = [this](auto p)
    {
        return buildCommandParametersStorage(p);
    };
    m_rp_converters[HciReadBDAddr] = [this](auto p)
    {
        return buildReturnParametersStorage<InformationalParameters, HciReadBDAddr>(p);
    };
}

std::shared_ptr<ConvertedValueAndPtr> HciCommandsConverter::getCommandParametersStorage(const HciCommand& cmd) const
{
    const auto opcode = cmd_opcode_pack(cmd.getOgf(), cmd.getOcf());
    auto converter_it = m_cp_converters.find(opcode);

    if (converter_it == m_cp_converters.end())
    {
        throw common::exceptions::IncorrectValueException(
            "[HciCommandsConverter] Command params converter not provided for "
            "OGF: " + std::to_string(cmd.getOgf()) + " OCF: " + std::to_string(cmd.getOcf()));

    }
    return (converter_it->second)(cmd.getCommandParameters());
}

std::shared_ptr<ConvertedValueAndPtr> HciCommandsConverter::getReturnParametersStorage(const HciCommand& cmd) const
{
    const auto opcode = cmd_opcode_pack(cmd.getOgf(), cmd.getOcf());
    auto converter_it = m_rp_converters.find(opcode);

    if (converter_it == m_rp_converters.end())
    {
        throw common::exceptions::IncorrectValueException(
            "[HciCommandsConverter] Return params converter not provided for "
            "OGF: " + std::to_string(cmd.getOgf()) + " OCF: " + std::to_string(cmd.getOcf()));
    }
    return (converter_it->second)(cmd.getReturnParameters());
}

std::shared_ptr<ConvertedValueAndPtr> HciCommandsConverter::buildCommandParametersStorage(const CommandParametersVariant& params)
{
    return std::make_shared<ConvertedValueAndPtr>(std::any(), nullptr);
}

template<>
std::shared_ptr<ConvertedValueAndPtr> HciCommandsConverter::buildReturnParametersStorage<InformationalParameters, HciReadBDAddr>(
    const ReturnParametersVariant& params)
{
    if (not std::holds_alternative<defs::HciReadBDAddrReturnParameters>(params))
    {
        throw common::exceptions::IncorrectValueException("[ConnectionCompleteHandler] Incorrect event received.");
    }
    auto& params_values = std::get<defs::HciReadBDAddrReturnParameters>(params);
    auto p = std::make_shared<read_bd_addr_rp>();
    p->status = static_cast<uint8_t>(params_values.status);
    p->bdaddr = params_values.bt_device_address.getRaw();
    return std::make_shared<ConvertedValueAndPtr>(std::move(p), p.get());
}


} // namespace connection::defs
