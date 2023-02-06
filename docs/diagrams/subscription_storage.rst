@startuml

actor Client
actor SubscriptionsStorage
actor Server

Server ->  SubscriptionsStorage : registerRequestExecutor(HciCommand::opcode, Executor)
Client ->  SubscriptionsStorage : request(HciCommand)
SubscriptionsStorage -> Server  : execute(Executor, HciCommand)
Server -> SubscriptionsStorage  : response(HciCommand)
SubscriptionsStorage -> Client  : callback(HciCommand)

@enduml