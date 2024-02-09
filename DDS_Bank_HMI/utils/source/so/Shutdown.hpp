#ifndef UTILS_SO_SHUTDOWN_HPP
#define UTILS_SO_SHUTDOWN_HPP

#include <iostream>
#include <csignal>

namespace  utils
{
namespace so
{

// Catch control-C and tell application to shut down
//TODO
bool shutdown_requested = false;

inline void stop_handler(int)
{
//TODO
    shutdown_requested = true;
    std::cout << "preparing to shut down..." << std::endl;
}

inline void setup_signal_handlers()
{
    signal(SIGINT, stop_handler);
    signal(SIGTERM, stop_handler);
}

}
}
#endif // UTILS_SO_SHUTDOWN_HPP
