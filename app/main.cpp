/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#include <connection/ConnectionModule.hpp>
#include <csignal>
#include <iostream>

std::atomic<bool> app_is_running = true;

void signal_handler(int sig)
{
    std::cout << "Received signal: " << sig << std::endl;
    app_is_running = false;
}

int main()
{
    connection::ConnectionModule module_1;
    module_1.activate();
    signal(SIGINT, signal_handler);
    signal(SIGABRT, signal_handler);
    signal(SIGTERM, signal_handler);

    while (app_is_running)
    {
    }
    return EXIT_SUCCESS;
}
