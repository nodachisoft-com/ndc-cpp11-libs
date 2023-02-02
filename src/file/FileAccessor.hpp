#pragma once

#include "../memory_bank/index.hpp"
#include <string>

enum class FileStatus
{
  READING,
  AVAILABLE,
  WRITTINGS,
  NOT_LOADING
};

enum class FileType
{
  FILE_NOT_FOUND,
  DIR,
  FILE
};

class FileAccessor
{
private:
  MemoryBank memory;
  std::string filePath;
  long filesize;
  FileType filetype;
  bool isOpenFile;
  float progress;
  FileStatus fileStatus;

public:
  FileAccessor();

  long calcCrc32();
  void readFileSync();
  void writeFileSync();
  void appendStringSync(std::string text);
};
