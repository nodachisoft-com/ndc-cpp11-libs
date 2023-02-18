#pragma once
#include <vector>
#include <iostream>
#include "../timewatch/index.hpp"

namespace nl
{
  class Logger
  {
    // constexpr outputLv = 1; // 0: DEBUG, 1:INFO, 2:ERROR

  private:
    bool isOutputToConsole;
    bool isOutputToFile;
    void outputToConsole(const std::string &msg, const std::string &logLevel)
    {
      if (isOutputToConsole)
      {
        std::string timestamp = TimeWatch::getNowMsAsStr_hhmmssSSS();
        std::cout << "[" << logLevel << " " << timestamp << "] " << msg << std::endl;
      }
    }

  public:
    Logger();
    Logger(std::string filepath);
    void debugLog(const std::string &msg);
    void infoLog(const std::string &msg);
    void errorLog(const std::string &msg);
  };
}
