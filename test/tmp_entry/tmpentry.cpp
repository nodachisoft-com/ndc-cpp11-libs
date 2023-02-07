#include "../../src/ndclibs.hpp"
#include <string>
#include <vector>

int main()
{
  /*

  std::string ttt("ttttt");

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
  /*
 std::cout << "FILES" << std::endl;
 std::vector<FileAccessor> result = FileAccessMgr::getFilesRecursively(std::string("./"));

 std::cout << "FILE COUNT:" << result.size() << std::endl;
 for (int i = 0; i < result.size(); i++)
 {
   std::cout << "FILES:" << result[i].getFilePath() << std::endl;
 }
 */
  /*
    FileAccessor fa("BBBB.txt");
    fa.appendStringSync("demobbbbb");
    fa.appendStringSync("DDDDD");
  */

  const std::string TESTTMP_DIR("./debug");
  FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2");
  FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/001");
  FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/002");
  FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/003");
  FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/004");
  FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/004/ab");
  FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/004/cde");

  std::vector<FileAccessor> files = FileAccessMgr::getDirsRecursively("./debug");

  std::cout << files.size() << std::endl;
  for (int i = 0; i < files.size(); i++)
  {
    std::cout << "FILE :" << files[i].getFilePath() << std::endl;
  }
}
