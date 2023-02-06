/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_DEFS_HCIRETURNPARAMETERSCONVERTER_HPP_
#define CONNECTION_DEFS_HCIRETURNPARAMETERSCONVERTER_HPP_

#include <connection/defs/IHciReturnParametersConverter.hpp>

#include <functional>

namespace connection::defs
{

class HciReturnParametersConverter : public IHciReturnParametersConverter
{
public:
    HciReturnParametersConverter();

    ReturnParametersVariant convert(const std::shared_ptr<hci_request>& req) override;

protected:
    void init();

    template <typename rp_type>
    ReturnParametersVariant convertReturnParameters(const std::shared_ptr<hci_request>& req);

private:
    using Converter = std::function<ReturnParametersVariant(const std::shared_ptr<hci_request>&)>;
    std::map<std::uint16_t, Converter> m_converters;
};

template<>ReturnParametersVariant HciReturnParametersConverter::convertReturnParameters<read_bd_addr_rp>(const std::shared_ptr<hci_request>& req);

} // namespace connection::defs

#endif // CONNECTION_DEFS_HCIRETURNPARAMETERSCONVERTER_HPP_
