#include "FileAccessor.hpp"
#include "FileAccessMgr.hpp"

FileAccessor::FileAccessor(std::string _filepath)
{
  filePath = _filepath;
  filesize = 0;
  isOpenFile = false;

  fileStatus = FileStatus::NOT_LOADING;
  progress = 0.0f;

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

long FileAccessor::calcCrc32()
{
  return 0;
}

void FileAccessor::readFileSync()
{
}

void FileAccessor::writeFileSync()
{
}

void FileAccessor::appendStringSync(std::string text)
{
}
