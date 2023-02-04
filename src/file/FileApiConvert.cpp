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

bool FileApiConvert::wrappedMkDir(std::string dirname)
{
#if defined(_WIN32) && defined(__GNUC__)
  // Windows 上の Mingw で gcc コンパイルした場合
  if (mkdir(dirname.c_str()) == 0)
  {
    // ディレクトリ作成成功
    return true;
  }
  return false;
#elif defined(_WIN32) && defined(_MSC_VER)
  // MS VC でコンパイルした場合
  // _mkdir は direct.h に含まれる
  if (_mkdir(dirname.c_str()) == 0)
  {
    // ディレクトリ作成成功
    return true;
  }
  return false;
#else
  // mkdir は <sys/stat.h> に含まれる
  if (mkdir(dirname.c_str(), 0777) == 0)
  {
    // Directory 作成成功
    return true;
  }
  return false;
#endif
}
