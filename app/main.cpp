/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#include <connection/ConnectionModule.hpp>
#include <csignal>
#include <iostream>

std::atomic_flag app_is_running = true;

void signal_handler(int sig)
{
    std::cout << "Received signal: " << sig << std::endl;
    app_is_running.clear();
    app_is_running.notify_all();
}

int main()
{
    connection::ConnectionModule module_1;
    module_1.activate();
    signal(SIGINT, signal_handler);
    app_is_running.wait(/*old=*/true);
    std::cout << "DONE "<< std::endl;
    return EXIT_SUCCESS;
}
