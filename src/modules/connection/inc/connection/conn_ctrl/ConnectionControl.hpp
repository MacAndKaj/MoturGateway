/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_CONN_CTRL_CONNECTIONCONTROL_HPP_
#define CONNECTION_CONN_CTRL_CONNECTIONCONTROL_HPP_

#include <log/ILogger.hpp>
#include <connection/hci/ISubscriptionsStorage.hpp>
#include <connection/conn_ctrl//ProcessingQueue.hpp>

namespace connection::conn_ctrl
{

class ConnectionControl
{
public:
    ConnectionControl(utils::IConnectionContext& context);

    virtual ~ConnectionControl() = default;
    void setup();
    void process();

protected:
    void callback(const defs::HciEvent& ev);

private:
    hci::ISubscriptionsStorage& m_subscriptions_storage;
    common::log::ILogger& m_logger;
    ProcessingQueue m_processing_queue;
};


} // namespace connection::conn_ctrl

#endif // CONNECTION_CONN_CTRL_CONNECTIONCONTROL_HPP_
