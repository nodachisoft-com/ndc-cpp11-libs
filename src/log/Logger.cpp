#include "Logger.hpp"

using namespace nl;

Logger::Logger()
    : isOutputToConsole(true), isOutputToFile(false)
{
}

void Logger::debugLog(const std::string &msg)
{
  outputToConsole(msg, "DEBUG");
}

void Logger::infoLog(const std::string &msg)
{
  outputToConsole(msg, "INFO ");
}

void Logger::errorLog(const std::string &msg)
{
  outputToConsole(msg, "ERROR");
}
