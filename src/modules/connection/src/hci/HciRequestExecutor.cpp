/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/
#include <connection/hci/HciRequestExecutor.hpp>

#include <connection/hci/handlers/ReadBDAddrHandler.hpp>
#include <utility>
#include <connection/hci/RequestsExecutionQueue.hpp>

namespace connection::hci
{

HciRequestExecutor::HciRequestExecutor(utils::IConnectionContext& context)
    : m_requests_socket(context.getHciObjectsBuilder().buildHciSocket())
    , m_subscriptions_storage(context.getSubscriptionsStorage())
    , m_logger(context.getLogger())
    , m_execution_queue(std::make_unique<RequestsExecutionQueue>())
{
    setup();
}

void HciRequestExecutor::work()
{
    // check queue for requests
    // execute request if pending
    while (not m_execution_queue->empty())
    {
        auto& cmd = m_execution_queue->first();
        auto handler_iter = m_handlers.find(cmd.getOpcode());
        if (handler_iter != m_handlers.end())
        {
            handler_iter->second->run(cmd);
        }
        else
        {
            m_logger.warn("[HciRequestExecutor] Handler not registerd for OGF: " + std::to_string(cmd.getOgf()) +
                " OCF: " + std::to_string(cmd.getOcf()));
            m_execution_queue->pop();
        }
    }
}

void HciRequestExecutor::setup()
{
    // build handlers for requests
    m_handlers.emplace(handlers::ReadBDAddrHandler::create());

    // register handlers as executors
    for (auto& [opcode, _] : m_handlers)
    {
        m_subscriptions_storage.registerRequestExecutor(
            opcode,
            [this](auto p1, auto p2){
                executeRequest(p1, p2);
            });
    }

    m_logger.info("[HciRequestExecutor] Setup correct");
}

void HciRequestExecutor::executeRequest(std::shared_ptr<defs::HciCommand> cmd, unsigned int req_id)
{
    m_logger.info("[HciRequestExecutor] New request with id " + std::to_string(req_id) + " added to queue");
    m_execution_queue->add(std::move(cmd), req_id);
}

} // namespace connection::hci
