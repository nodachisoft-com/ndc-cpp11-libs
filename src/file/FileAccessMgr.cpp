#include "FileAccessMgr.hpp"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_MSC_VER)
#include <direct.h>
#define getcwd _getcwd
#elif defined(__GNUC__)
#include <unistd.h>
#endif

FileAccessMgr::FileAccessMgr()
{
}

void FileAccessMgr::mkdir(std::string dirname)
{
  errno = 0;
  if (mkdir(dirname.c_str(), 0777) == 0)
    printf("ディレクトリ%sを作成しました。\n", dirname.c_str());
  else
  {
    if (errno == EEXIST)
    {
      printf("ディレクトリ%sは既に存在します。\n", dir);
    }
    else if (errno == ENOENT)
    {
      printf("パス%sが存在しません。\n", dir);
    }
    else
    {
      printf("ディレクトリ%sを作成できませんでした。\n", dir);
    }

    // errnoを0に戻しておく
    errno = 0;
  }
}

void FileAccessMgr::rmdir1(std::string filename)
{
  // rmdir(filename.c_str());
}

void FileAccessMgr::rmfile1(std::string filename) {}

FileType FileAccessMgr::isExistFileOrDir(std::string filepath)
{
  FILE *fp = fopen(path, "r");
  if (fp == NULL)
  {
    return false;
  }
  fclose(fp);
  return FileType::FILE_NOT_FOUND;
}

FileAccessor FileAccessMgr::getFileInfo(std::string filename)
{
  FileAccessor fa;
  return fa;
}

std::string FileAccessMgr::getCurDir()
{
  _getcwd(buf, MAX_PATH);
  return std::string("/test/xxx/");
}

FileAccessor *FileAccessMgr::getFilesRecursively(std::string dirPath)
{
  return NULL;
}
