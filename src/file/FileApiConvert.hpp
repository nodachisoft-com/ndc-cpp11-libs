#pragma once
#include <string>
#include <iostream>

#include <unistd.h>

#if defined(_MSC_VER)
// Windows 環境
#include <direct.h> // Microsoft の File API 利用

#elif defined(__GNUC__)
// Linux 環境
#include <unistd.h>
#include <sys/stat.h>
#endif

/*
#if defined(_MSC_VER)
// Windows 環境
#include <direct.h> // Microsoft の API 利用
#define getcwd _getcwd
#elif defined(__GNUC__)
// Linux 環境
#include <unistd.h>
#endif
*/

class FileApiConvert
{
public:
  static std::string wrappedGetCwd();
  static bool wrappedMkDir(std::string dirname);
};
