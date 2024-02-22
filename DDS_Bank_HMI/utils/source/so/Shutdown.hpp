#ifndef UTILS_SO_SHUTDOWN_HPP
#define UTILS_SO_SHUTDOWN_HPP

#include <csignal>
#include <iostream>

namespace utils
{
namespace so
{

// Catch control-C and tell application to shut down
extern bool shutdownRequested;

inline void stopHandler(int)
{
  shutdownRequested = true;
  std::cout << "preparing to shut down..." << std::endl;
}

inline void setupSignalHandlers()
{
  signal(SIGINT, stopHandler);
  signal(SIGTERM, stopHandler);
}

}  // namespace so
}  // namespace utils

#endif  // UTILS_SO_SHUTDOWN_HPP
