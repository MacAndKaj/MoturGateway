/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include <connection/utils/ConnectionContext.hpp>

namespace connection::utils
{

common::log::MainLogger& ConnectionContext::getMainLogger() const
{
    return *m_main_logger;
}


} // namespace connection::utils
