#include "FileAccessor.hpp"
#include "FileAccessMgr.hpp"

FileAccessor::FileAccessor(std::string _filepath)
{
  filePath = _filepath;
  filesize = 0;
  isOpenFileFlag = false;

  fileStatus = FileStatus::NOT_LOADING;
  progress = 0.0f;

  memory = new MemoryBank();

  struct stat st;
  int statResult = stat(_filepath.c_str(), &st);
  if (statResult != 0)
  {
    // 読み取りエラー
    filetype = FileType::FILE_NOT_FOUND;
  }
  filetype = FileAccessMgr::isExistFileOrDir(_filepath); // ファイルタイプ取得
  if (filetype == FileType::FILE)
  {
    filesize = st.st_size; // ファイルサイズ取得
  }
}

long FileAccessor::calcMemoryCrc32()
{
  return 0;
}

void FileAccessor::readFileSync()
{
  long READ_BLOCK_LENGTH = 16;
  FILE *fp = fopen(filePath.c_str(), "rb");
  if (fp == NULL)
  {
    // ファイルオープンエラーの処理
    return;
  }

  // ファイルサイズの取得
  if (fseek(fp, 0, SEEK_END) != 0)
  {
    // fseek エラーの処理
  }

  long fileByteSize = ftell(fp);

  if (fseek(fp, 0L, SEEK_SET) != 0)
  {
    // fseek エラーの処理
  }

  // ファイル全体を格納するメモリを割り当てる
  char *buffer = (char *)malloc(READ_BLOCK_LENGTH);
  if (buffer == NULL)
  {
    // メモリ割り当てエラーの処理
  }

  while (true)
  {
    int readByteLength = fread(buffer, 1, READ_BLOCK_LENGTH, fp);
    for (int c = 0; c < readByteLength; c++)
    {
      memory->appendByte(buffer[c]);
    }
    if (readByteLength < READ_BLOCK_LENGTH)
    {
      // ファイル読み取り終了
      break;
    }
  }
  free(buffer);
  fclose(fp);
}

void FileAccessor::writeFileSync()
{
}

void FileAccessor::appendStringSync(std::string text)
{
}

MemoryBank *FileAccessor::getMemoryBank()
{
  return memory;
}
void FileAccessor::setMemoryBank(MemoryBank *_memory)
{
  if (memory != NULL)
  {
    // 既存のメモリを解放
    delete memory;
  }
  memory = _memory;
}
std::string FileAccessor::getFilePath()
{
  return filePath;
}
void FileAccessor::setFilePath(std::string _filePath)
{
  filePath = std::string(_filePath);
}
long FileAccessor::getFilesize()
{
  return filesize;
}
FileType FileAccessor::getFiletype()
{
  return filetype;
}
bool FileAccessor::isOpenFile()
{
  return isOpenFileFlag;
}
float FileAccessor::getProgress()
{
  return progress;
}
FileStatus FileAccessor::getFileStatus()
{
  return fileStatus;
}
