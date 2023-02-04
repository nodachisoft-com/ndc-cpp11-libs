#include "../../src/ndclibs.hpp"
#include <string>
#include <vector>

int main()
{
  /*
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
  */

  /*
    FileAccessor fa = FileAccessMgr::getFileInfo(std::string("aiueo.txt"));
    fa.readFileSync();
    MemoryBank *mem = fa.getMemoryBank();
    int size = mem->getUsingSize();
    for (int i = 0; i < size; i++)
    {
      std::cout << mem->readChar();
    }
    printf("CRC32=%x\n", mem->calcCrc32());

    Crc32 crc;
    char text[] = "abcd";
    for (int i = 0; i < 4; i++)
    {
      crc.calcUpdate(text[i]);
    }
    // EXPECT_EQ(3984772369, crc.getHash());
    printf("abcd crc32=%x\n", crc.getHash());
    MemoryBank t;
    t.appendByte('a');
    t.appendByte('b');
    t.appendByte('c');
    t.appendByte('d');
    printf("abcd MemoryBank crc32=%x\n", t.calcCrc32());

    fa.setFilePath(std::string("XXX.txt"));
    fa.writeFileSync();
    */
  std::cout << "DIRECTORY" << std::endl;
  std::vector<FileAccessor> result = FileAccessMgr::getDirsRecursively(std::string("./"));

  std::cout << "DIRLEN:" << result.size() << std::endl;
  for (int i = 0; i < result.size(); i++)
  {
    std::cout << "DIR:" << result[i].getFilePath() << std::endl;
  }
}
