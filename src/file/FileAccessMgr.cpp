#include "FileAccessMgr.hpp"

FileAccessMgr::FileAccessMgr()
{
}

bool FileAccessMgr::makedir(std::string dirname)
{
  return FileApiConvert::wrappedMkDir(dirname);
}

bool FileAccessMgr::removedir(std::string filename)
{
  return FileApiConvert::wrappedRmDir(filename);
}

bool FileAccessMgr::removefile(std::string filename)
{
  return FileApiConvert::wrappedRmFile(filename);
}

FileType FileAccessMgr::isExistFileOrDir(std::string filepath)
{
  struct stat st;
  int result = stat(filepath.c_str(), &st);
  if (result != 0)
  {
    return FileType::FILE_NOT_FOUND;
  }
  if ((st.st_mode & S_IFMT) == S_IFDIR)
  {
    // printf("%s is directory.\n", argv[1]);
    return FileType::DIR;
  }

  FILE *fp = fopen(filepath.c_str(), "r");
  if (fp == NULL)
  {
    return FileType::FILE_NOT_FOUND;
  }
  fclose(fp);
  return FileType::FILE;
}

FileAccessor FileAccessMgr::getFileInfo(std::string filename)
{
  FileAccessor fa;
  return fa;
}

std::string FileAccessMgr::getCurDir()
{
  return FileApiConvert::wrappedGetCwd();
}

FileAccessor *FileAccessMgr::getFilesRecursively(std::string dirPath)
{
  return NULL;
}
