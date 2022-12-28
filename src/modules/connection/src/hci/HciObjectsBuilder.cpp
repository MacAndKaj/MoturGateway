/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/hci/HciObjectsBuilder.hpp>

#include <connection/hci/HciSocket.hpp>

namespace connection::hci
{

HciObjectsBuilder::HciObjectsBuilder(common::log::ILogger &logger)
    : m_logger(logger)
{
}

std::unique_ptr<IHciSocket> HciObjectsBuilder::buildHciSocket() const
{
    return std::make_unique<HciSocket>(m_logger);
}

} // namespace connection::hci
