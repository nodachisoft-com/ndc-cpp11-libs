#include "../../src/ndclibs.hpp"
#include <string>
#include <vector>

int main()
{

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
