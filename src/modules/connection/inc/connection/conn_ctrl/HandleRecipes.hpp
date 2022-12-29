/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_CONN_CTRL_HANDLERECIPES_HPP_
#define CONNECTION_CONN_CTRL_HANDLERECIPES_HPP_

#include <connection/defs/HciTypes.hpp>

#include <functional>

namespace connection::conn_ctrl
{

class HandleRecipes
{
public:
    static std::function<void()> get(const defs::HciEvent& ev);
};


} // namespace connection::conn_ctrl

#endif // CONNECTION_CONN_CTRL_HANDLERECIPES_HPP_
