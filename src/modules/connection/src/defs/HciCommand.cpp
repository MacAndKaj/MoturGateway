/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/defs/HciCommand.hpp>

namespace connection::defs
{

HciCommand::HciCommandBuilder::HciCommandBuilder(utils::IConnectionContext& context)
    : m_temp(new HciCommand(context.getHciCommandsConverter(), context.getHciReturnParametersConverter()))
{
}

HciCommand::HciCommandBuilder HciCommand::builder(utils::IConnectionContext& context)
{
    return HciCommandBuilder(context);
}

HciCommand::HciCommandBuilder HciCommand::HciCommandBuilder::withOgf(uint8_t ogf) &&
{
    m_temp->m_ogf = ogf;
    return std::move(*this);
}

HciCommand::HciCommandBuilder HciCommand::HciCommandBuilder::withOcf(uint16_t ocf) &&
{
    m_temp->m_ocf = ocf;
    return std::move(*this);
}

HciCommand::HciCommandBuilder HciCommand::HciCommandBuilder::withCommandParameters(const CommandParametersVariant& params) &&
{
    m_temp->m_command_parameters = params;
    return std::move(*this);
}

HciCommand::HciCommandBuilder HciCommand::HciCommandBuilder::withReturnParameters(const ReturnParametersVariant& params) &&
{
    m_temp->m_return_parameters = params;
    return std::move(*this);
}

std::shared_ptr<HciCommand> HciCommand::HciCommandBuilder::build() &&
{
    return m_temp;
}

HciCommand::HciCommand(IHciCommandsConverter& converter,
                       IHciReturnParametersConverter& return_parameters_converter)
    : m_commands_converter(converter)
    , m_return_parameters_converter(return_parameters_converter)
{
}

std::shared_ptr<hci_request> HciCommand::buildRequest()
{
    auto req = std::make_shared<hci_request>();
    req->ogf = m_ogf;
    req->ocf = m_ocf;
    m_request_cp = m_commands_converter.getCommandParametersStorage(*this);
    req->cparam = m_request_cp->ptr;
    req->clen = command_parameters_size_map.at(cmd_opcode_pack(m_ogf, m_ocf));

    m_request_rp = m_commands_converter.getReturnParametersStorage(*this);
    req->rparam = m_request_rp->ptr;
    req->rlen = return_parameters_size_map.at(cmd_opcode_pack(m_ogf, m_ocf));
    return req;
}

void HciCommand::processResult(const std::shared_ptr<hci_request>& req)
{
    m_return_parameters = m_return_parameters_converter.convert(req);
}

uint16_t HciCommand::getOpcode() const
{
    return cmd_opcode_pack(m_ogf, m_ocf);
}

uint8_t HciCommand::getOgf() const
{
    return m_ogf;
}

uint16_t HciCommand::getOcf() const
{
    return m_ocf;
}

const CommandParametersVariant& HciCommand::getCommandParameters() const
{
    return m_command_parameters;
}

const ReturnParametersVariant& HciCommand::getReturnParameters() const
{
    return m_return_parameters;
}

} // namespace connection::defs
