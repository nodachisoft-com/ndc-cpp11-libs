#include "Logger.hpp"

using namespace nl;

Logger::Logger()
    : isOutputToConsole(true), isOutputToFile(false), isFiltered(false)
{
}

Logger::~Logger()
{
}

void Logger::doFilter(const std::string substr)
{
  isFiltered = true;
  filterCondition = std::regex(std::string(".*").append(substr).append(".*"));
}

void Logger::removeFilter()
{
  isFiltered = false;
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
