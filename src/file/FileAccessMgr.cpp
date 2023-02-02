#include "FileAccessMgr.hpp"
#include <sys/stat.h>

FileAccessMgr::FileAccessMgr()
{
}

void FileAccessMgr::mkdir(std::string filename)
{
}

void FileAccessMgr::rmdir(std::string filename)
{
}

void FileAccessMgr::rmfile(std::string filename) {}

FileType FileAccessMgr::isExistFileOrDir(std::string filepath)
{
  return FileType::FILE_NOT_FOUND;
}

FileAccessor FileAccessMgr::getFileInfo(std::string filename)
{
  FileAccessor fa;
  return fa;
}

std::string FileAccessMgr::getCurDir()
{
  return NULL;
}

FileAccessor *FileAccessMgr::getFilesRecursively(std::string dirPath)
{
  return NULL;
}
