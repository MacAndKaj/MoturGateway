/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_HCIOBJECTSBUILDER_HPP_
#define CONNECTION_HCI_HCIOBJECTSBUILDER_HPP_

#include <connection/hci/IHciObjectsBuilder.hpp>

#include <log/ILogger.hpp>

namespace connection::hci
{

class HciObjectsBuilder : public IHciObjectsBuilder
{
public:
    explicit HciObjectsBuilder(common::log::ILogger& logger);
    virtual ~HciObjectsBuilder() = default;

    std::unique_ptr<IHciSocket> buildHciSocket() const override;

private:
    common::log::ILogger& m_logger;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_HCIOBJECTSBUILDER_HPP_
