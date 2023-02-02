#pragma once
#include "FileAccessor.hpp"
#include <string>

class FileAccessMgr
{
public:
  FileAccessMgr();

  static void mkdir(std::string filename);

  static void rmdir(std::string filename);

  static void rmfile(std::string filename);

  static FileType isExistFileOrDir(std::string filepath);

  static FileAccessor getFileInfo(std::string filename);

  static std::string getCurDir();

  static FileAccessor *getFilesRecursively(std::string dirPath);
};
