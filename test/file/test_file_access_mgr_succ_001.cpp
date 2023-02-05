#include <gtest/gtest.h>
#include "../../src/ndclibs.hpp"

#include <string>

// #define TESTTMP_DIR ("debug/")
const std::string TESTTMP_DIR("./debug/");

// カレントディレクトリのパスを取得する
TEST(FileAccessMgr, curDir_case1)
{
  std::string curDir(FileAccessMgr::getCurDir());
  int length = curDir.length();
  // 1 以上の文字列が取得できていること
  EXPECT_GT(length, 1);
}

// ディレクトリ作成、情報取得、削除を行う
TEST(FileAccessMgr, directory_operation_case1)
{

  std::string targetDir = std::string(TESTTMP_DIR) + "makedir_case1";

  // 対象ディレクトリがまだ存在しないこと
  FileType dircheck1 = FileAccessMgr::isExistFileOrDir(targetDir);
  EXPECT_EQ(dircheck1, FileType::FILE_NOT_FOUND);

  // makedir が成功していること
  EXPECT_EQ(FileAccessMgr::makedir(targetDir), 1);

  // path の情報を取得し ディレクトリであること内容に問題ないこと
  FileType newDirAcc = FileAccessMgr::isExistFileOrDir(targetDir);
  EXPECT_EQ(newDirAcc, FileType::DIR);

  // removedir が成功していること
  EXPECT_EQ(FileAccessMgr::removedir(targetDir), 1);

  // 対象ディレクトリが削除されており、存在しないこと
  FileType dircheck2 = FileAccessMgr::isExistFileOrDir(targetDir);
  EXPECT_EQ(dircheck2, FileType::FILE_NOT_FOUND);
}

TEST(FileAccessMgr, getDirsRecursively_caseXXX)
{
  // FileAccessor fa("./debug/.gitkeep");
  /*
  DIR *dir;
  struct dirent *ent;
  std::string dirPath("./debug");
  std::string fileOrDirName;
  if ((dir = opendir(dirPath.c_str())) != NULL)
  {
    while ((ent = readdir(dir)) != NULL)
    {
      std::cout << "START LOOP" << std::endl;
      fileOrDirName = std::string(ent->d_name);
      std::cout << "FILE PATH:" << fileOrDirName << std::endl;
      if ((!(strlen(ent->d_name) == 1 && ent->d_name[0] == '.')) &&
          (!(strlen(ent->d_name) == 2 && ent->d_name[0] == '.' && ent->d_name[1] == '.')))
      {
        std::string fileTargetname(dirPath + "/" + fileOrDirName);
        std::cout << "FILE: " << fileTargetname << std::endl;
        FileAccessor fa(fileTargetname);
        // char *AA = (char *)malloc(1024 * 1024);
      }
    }
  }
  */
}

// 深いディレクトリを作成し、再帰的にデータを取得した後、ディレクトリを削除する
/*
TEST(FileAccessMgr, getDirsRecursively_case1)
{
  std::cout << "WEE0" << std::endl;

  std::vector<FileAccessor> files{};

  std::cout << "WEE0-1" << std::endl;
  files = FileAccessMgr::getDirsRecursively("./debug");
  EXPECT_EQ(files.size(), 0); // 0 件のディレクトリ

  std::cout << "WEE1" << std::endl;

  const std::string TESTTMP_DIR("./debug");
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2"), true);
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/001"), true);
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/002"), true);
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/003"), true);
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/004"), true);
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/004/ab"), true);
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/004/cde"), true);

  std::cout << "WEE2" << std::endl;

  // 一覧取得
  files = FileAccessMgr::getDirsRecursively("./debug");
  EXPECT_EQ(files.size(), 7); // 7 件のディレクトリが取得できている
  EXPECT_EQ(files[0].getFilePath(), TESTTMP_DIR + "/makedir_case2");
  EXPECT_EQ(files[1].getFilePath(), TESTTMP_DIR + "/makedir_case2/001");
  EXPECT_EQ(files[2].getFilePath(), TESTTMP_DIR + "/makedir_case2/002");
  EXPECT_EQ(files[3].getFilePath(), TESTTMP_DIR + "/makedir_case2/003");
  EXPECT_EQ(files[4].getFilePath(), TESTTMP_DIR + "/makedir_case2/004");
  EXPECT_EQ(files[5].getFilePath(), TESTTMP_DIR + "/makedir_case2/004/ab");
  EXPECT_EQ(files[6].getFilePath(), TESTTMP_DIR + "/makedir_case2/004/cde");
  std::cout << "WEE3" << std::endl;

  // ディレクトリの削除(深いほうから削除)
  EXPECT_EQ(FileAccessMgr::removedir(TESTTMP_DIR + "/makedir_case2/004/cde"), true);
  EXPECT_EQ(FileAccessMgr::removedir(TESTTMP_DIR + "/makedir_case2/004/ab"), true);
  EXPECT_EQ(FileAccessMgr::removedir(TESTTMP_DIR + "/makedir_case2/004"), true);
  EXPECT_EQ(FileAccessMgr::removedir(TESTTMP_DIR + "/makedir_case2/003"), true);
  EXPECT_EQ(FileAccessMgr::removedir(TESTTMP_DIR + "/makedir_case2/002"), true);
  EXPECT_EQ(FileAccessMgr::removedir(TESTTMP_DIR + "/makedir_case2/001"), true);
  EXPECT_EQ(FileAccessMgr::removedir(TESTTMP_DIR + "/makedir_case2"), true);

  // 一覧取得
  files = FileAccessMgr::getDirsRecursively("./debug");
  EXPECT_EQ(files.size(), 0); // 0 件のディレクトリ
}
*/
