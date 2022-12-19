/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#ifndef CONNECTION_HCI_IHCIOBJECTSBUILDER_HPP_
#define CONNECTION_HCI_IHCIOBJECTSBUILDER_HPP_

#include <connection/hci/IHciSocket.hpp>

#include <memory>

namespace connection::hci
{

class IHciObjectsBuilder
{
public:
    virtual ~IHciObjectsBuilder() = default;

    virtual std::unique_ptr<IHciSocket> buildHciSocket() const = 0;
};

} // namespace connection::hci

#endif // CONNECTION_HCI_IHCIOBJECTSBUILDER_HPP_
