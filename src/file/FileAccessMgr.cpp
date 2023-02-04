#include "FileAccessMgr.hpp"

FileAccessMgr::FileAccessMgr()
{
}

void FileAccessMgr::makedir(std::string dirname)
{
  errno = 0;
  if (mkdir(dirname.c_str(), 0777) == 0)
    // if (mkdir(dirname.c_str()) == 0)
    printf("ディレクトリ%sを作成しました。\n", dirname.c_str());
  else
  {
    if (errno == EEXIST)
    {
      printf("ディレクトリ%sは既に存在します。\n", dirname.c_str());
    }
    else if (errno == ENOENT)
    {
      printf("パス%sが存在しません。\n", dirname.c_str());
    }
    else
    {
      printf("ディレクトリ%sを作成できませんでした。\n", dirname.c_str());
    }

    // errnoを0に戻しておく
    errno = 0;
  }
}

void FileAccessMgr::removedir(std::string filename)
{
  // rmdir(filename.c_str());
}

void FileAccessMgr::removefile(std::string filename) {}

FileType FileAccessMgr::isExistFileOrDir(std::string filepath)
{
  FILE *fp = fopen(filepath.c_str(), "r");
  if (fp == NULL)
  {
    return FileType::FILE_NOT_FOUND;
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
  return FileApiConvert::wrappedGetCwd();
}

FileAccessor *FileAccessMgr::getFilesRecursively(std::string dirPath)
{
  return NULL;
}
