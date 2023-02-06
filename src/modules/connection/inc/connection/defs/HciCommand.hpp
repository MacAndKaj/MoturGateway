/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_DEFS_HCICOMMAND_HPP_
#define CONNECTION_DEFS_HCICOMMAND_HPP_

#include <connection/defs/HciCommandTypes.hpp>
#include <connection/defs/IHciCommandsConverter.hpp>
#include <connection/defs/IHciReturnParametersConverter.hpp>
#include <connection/utils/IConnectionContext.hpp>

#include <bluetooth/hci_lib.h>

#include <memory>
#include <any>

namespace connection::defs
{

class HciCommand
{
public:
    class HciCommandBuilder
    {
    public:
        explicit HciCommandBuilder(utils::IConnectionContext& context);
        HciCommandBuilder withOgf(uint8_t ogf) &&;
        HciCommandBuilder withOcf(uint16_t ocf) &&;
        HciCommandBuilder withCommandParameters(const CommandParametersVariant& params) &&;
        HciCommandBuilder withReturnParameters(const ReturnParametersVariant& params) &&;
        std::shared_ptr<HciCommand> build() &&;
    private:
        std::shared_ptr<HciCommand> m_temp;
    };

    static HciCommandBuilder builder(utils::IConnectionContext& context);

    std::shared_ptr<hci_request> buildRequest();
    void processResult(const std::shared_ptr<hci_request>& req);

    uint16_t getOpcode() const;
    uint8_t getOgf() const;
    uint16_t getOcf() const;
    const CommandParametersVariant& getCommandParameters() const;
    const ReturnParametersVariant& getReturnParameters() const;

protected:
    HciCommand(IHciCommandsConverter& commands_converter,
               IHciReturnParametersConverter& return_parameters_converter);

private:
    IHciCommandsConverter& m_commands_converter;
    IHciReturnParametersConverter& m_return_parameters_converter;
    std::uint8_t m_ogf{0};
    std::uint16_t m_ocf{0};
    CommandParametersVariant m_command_parameters;
    ReturnParametersVariant m_return_parameters;
    std::shared_ptr<ConvertedValueAndPtr> m_request_cp;
    std::shared_ptr<ConvertedValueAndPtr> m_request_rp;
};


} // namespace connection::defs

#endif // CONNECTION_DEFS_HCICOMMAND_HPP_
