/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/conn_ctrl/ConnectionControl.hpp>
#include <connection/conn_ctrl/HandleRecipes.hpp>

namespace connection::conn_ctrl
{

ConnectionControl::ConnectionControl(utils::IConnectionContext& context)
    : m_subscriptions_storage(context.getSubscriptionsStorage())
    , m_logger(context.getLogger())
{
}

void ConnectionControl::setup()
{
    //TODO: move it out from here
    for (const auto& ev_name: {
        defs::HciEventName::ConnectionRequest,
        defs::HciEventName::ConnectionComplete,
        defs::HciEventName::InquiryComplete,
        defs::HciEventName::InquiryResult,
    })
    {
        m_subscriptions_storage.subscribe(
            ev_name,
            [this](auto&& event) { callback(std::forward<decltype(event)>(event));}
        );
    }
}

void ConnectionControl::process()
{
    m_processing_queue.evaluate();
}

void ConnectionControl::callback(const defs::HciEvent& ev)
{

    auto handler = HandleRecipes::get(ev);
    m_processing_queue.addJob(std::make_unique<Job>(handler));
}

} // namespace connection::conn_ctrl
