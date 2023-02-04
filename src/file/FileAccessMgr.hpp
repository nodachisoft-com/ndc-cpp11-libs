#pragma once
#include "FileApiConvert.hpp"
#include "FileAccessor.hpp"

#include <string>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class FileAccessMgr
{
public:
  FileAccessMgr();

  static void makedir(std::string filename);

  static void removedir(std::string filename);

  static void removefile(std::string filename);

  static FileType isExistFileOrDir(std::string filepath);

  static FileAccessor getFileInfo(std::string filename);

  static std::string getCurDir();

  static FileAccessor *getFilesRecursively(std::string dirPath);
};
