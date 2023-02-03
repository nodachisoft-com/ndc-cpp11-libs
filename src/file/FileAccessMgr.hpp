#pragma once
#include "FileAccessor.hpp"
#include <string>

class FileAccessMgr
{
public:
  FileAccessMgr();

  static void mkdir1(std::string filename);

  static void rmdir1(std::string filename);

  static void rmfile1(std::string filename);

  static FileType isExistFileOrDir(std::string filepath);

  static FileAccessor getFileInfo(std::string filename);

  static std::string getCurDir();

  static FileAccessor *getFilesRecursively(std::string dirPath);
};
