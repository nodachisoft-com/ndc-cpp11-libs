#include "../../src/ndclibs.hpp"
// #include "../../src/image/index.hpp"

int main()
{
  std::string path = FileAccessMgr::getCurDir();
  std::cout << "PATH=" << path << std::endl;

  int r = 0;

  std::string ttt("ttttt");

  FileType filetype = FileAccessMgr::isExistFileOrDir(ttt);
  if (filetype == FileType::FILE_NOT_FOUND)
  {
    std::cout << "OK: Directory Not Found" << std::endl;
  }
  else
  {
    std::cout << "NG: Directory Found" << std::endl;
  }

  if (FileApiConvert::wrappedMkDir(ttt))
  {
    std::cout << "OK: mkdir Succ!" << std::endl;
  }
  else
  {
    std::cout << "NG: mk failed" << std::endl;
  }

  filetype = FileAccessMgr::isExistFileOrDir(ttt);
  if (filetype == FileType::DIR)
  {
    std::cout << "OK: Directory Found" << std::endl;
  }
  else
  {
    std::cout << "NG: Directory Not Found" << std::endl;
  }

  if (FileApiConvert::wrappedMkDir(ttt))
  {
    std::cout << "mk Succ!" << std::endl;
  }
  else
  {
    std::cout << "mk failed" << std::endl;
  }

  if (FileApiConvert::wrappedRmDir(ttt))
  {
    std::cout << "rmdir succ" << std::endl;
  }
  else
  {
    std::cout << "rmdir failed" << std::endl;
  }

  if (FileApiConvert::wrappedRmFile(ttt))
  {
    std::cout << "file removed!" << std::endl;
  }
  else
  {
    std::cout << "file NOT removed!" << std::endl;
  }

  filetype = FileAccessMgr::isExistFileOrDir(std::string("README.md"));
  if (filetype == FileType::FILE)
  {
    std::cout << "OK: README.md file Found" << std::endl;
  }
  else
  {
    std::cout << "NG: README.md file NOT Found" << std::endl;
  }
}
