/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/

#include <connection/conn_ctrl/ConnectionControl.hpp>
#include <connection/conn_ctrl/HandleRecipes.hpp>
#include <connection/conn_ctrl/scenarios/StartupScenario.hpp>

namespace connection::conn_ctrl
{

ConnectionControl::ConnectionControl(utils::IConnectionContext& context)
    : m_subscriptions_storage(context.getSubscriptionsStorage())
    , m_logger(context.getLogger())
    , m_processing_queue(context)
    , m_recipes(context)
{
    setup();
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
        m_sub_guards.emplace_back(
            m_subscriptions_storage.subscribe(
                ev_name,
                [this](auto&& event) { callback(std::forward<decltype(event)>(event));}
            ));
    }

    m_processing_queue.addJob(std::make_unique<Job>(scenarios::StartupScenario::create()));
}

void ConnectionControl::process()
{
    m_processing_queue.evaluate();
}

void ConnectionControl::callback(const defs::HciEvent& ev)
{
    auto handler = m_recipes.get(ev);
    m_processing_queue.addJob(std::make_unique<Job>(handler));
}

} // namespace connection::conn_ctrl
