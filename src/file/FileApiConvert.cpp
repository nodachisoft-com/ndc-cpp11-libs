#include "FileApiConvert.hpp"

std::string FileApiConvert::wrappedGetCwd()
{

#if defined(_MSC_VER)
  // Windows 環境
  std::cout << "[DEBUG] FileApiConvert::wrappedGetCwd() : Windows 環境用 GetCWD" << std::endl;
  return std::string(_getcwd(), 1024 * 64);
#elif defined(__GNUC__)

  // GCC 環境向け
  std::cout << "[DEBUG] FileApiConvert::wrappedGetCwd() : Linux 環境用 GetCWD" << std::endl;
  char path[1024 * 4];
  getcwd(path, 1024 * 4);
  return std::string(path);
#endif
};
