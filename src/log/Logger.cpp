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
  setFontColorRGB(100, 100, 150);
  outputToConsole(msg, "DEBUG");
  resetColor();
}

void Logger::infoLog(const std::string &msg)
{
  setFontColorRGB(0, 155, 255);
  outputToConsole(msg, "INFO ");
  resetColor();
}

void Logger::errorLog(const std::string &msg)
{
  setFontColorRGB(205, 30, 0);
  outputToConsole(msg, "ERROR");
  resetColor();
}
