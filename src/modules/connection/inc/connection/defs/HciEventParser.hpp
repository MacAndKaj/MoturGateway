/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_DEFS_HCIEVENTPARSER_HPP_
#define CONNECTION_DEFS_HCIEVENTPARSER_HPP_

#include <connection/defs/HciTypes.hpp>

#include <string>

namespace connection::defs
{

class HciEventParser
{
public:
    static HciEvent getHciEvent(const char* data);

protected:
    template<typename ev_type>
    static HciEvent convert(const ev_type& ev);
};

template<>HciEvent HciEventParser::convert(const char& ev);
template<>HciEvent HciEventParser::convert(const inquiry_info& ev);
template<>HciEvent HciEventParser::convert(const evt_conn_request& ev);
template<>HciEvent HciEventParser::convert(const evt_conn_complete& ev);


} // namespace connection::defs

#endif // CONNECTION_DEFS_HCIEVENTPARSER_HPP_
