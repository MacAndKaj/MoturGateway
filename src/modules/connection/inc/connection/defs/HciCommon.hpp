/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_DEFS_HCICOMMON_HPP_
#define CONNECTION_DEFS_HCICOMMON_HPP_

namespace connection::defs
{

enum class Status
{
    NoError,
    UnknownHciCommand,
    UnknownConnectionIdentifier,
    HardwareFailure,
    PageTimout,
    AuthenticationFailure
    // TODO: others
};

} // namespace connection::defs

#endif // CONNECTION_DEFS_HCICOMMON_HPP_
