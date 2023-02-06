/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_DEFS_HCICOMMANDSCONVERTER_HPP_
#define CONNECTION_DEFS_HCICOMMANDSCONVERTER_HPP_

#include <connection/defs/IHciCommandsConverter.hpp>
#include <connection/defs/HciCommandTypes.hpp>

#include <bluetooth/hci_lib.h>

#include <functional>
#include <map>
#include <memory>

namespace connection::defs
{

class HciCommandsConverter : public IHciCommandsConverter
{
public:
    HciCommandsConverter();

    std::shared_ptr<ConvertedValueAndPtr> getCommandParametersStorage(const HciCommand& cmd) const override;
    std::shared_ptr<ConvertedValueAndPtr> getReturnParametersStorage(const HciCommand& cmd) const override;

protected:
    void init();

    template <std::uint8_t OGF, std::uint16_t OCF>
    std::shared_ptr<ConvertedValueAndPtr> buildCommandParametersStorage(const CommandParametersVariant& params);

    template <std::uint8_t OGF, std::uint16_t OCF>
    std::shared_ptr<ConvertedValueAndPtr> buildReturnParametersStorage(const ReturnParametersVariant& params);

    std::shared_ptr<ConvertedValueAndPtr> buildReturnParametersStorage(const ReturnParametersVariant& params);
    std::shared_ptr<ConvertedValueAndPtr> buildCommandParametersStorage(const CommandParametersVariant& params);

private:
    using CmdConverter = std::function<std::shared_ptr<ConvertedValueAndPtr>(const CommandParametersVariant& params)>;
    using RetConverter = std::function<std::shared_ptr<ConvertedValueAndPtr>(const ReturnParametersVariant& params)>;

    std::map<std::uint16_t, CmdConverter> m_cp_converters;
    std::map<std::uint16_t, RetConverter> m_rp_converters;
};

template<>std::shared_ptr<ConvertedValueAndPtr> HciCommandsConverter::buildReturnParametersStorage<InformationalParameters, HciReadBDAddr>(const ReturnParametersVariant& params);

} // namespace connection::defs

#endif // CONNECTION_DEFS_HCICOMMANDSCONVERTER_HPP_
