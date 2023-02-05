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
  FileAccessor dircheck1 = FileAccessMgr::isExistFileOrDir(targetDir);
  EXPCT_EQ(dircheck1.getFiletype, FileType::FILE_NOT_FOUND);

  // makedir が成功していること
  EXPECT_EQ(FileAccessMgr::makedir(targetDir), 1);

  // path の情報を取得し ディレクトリであること内容に問題ないこと
  FileAccessor newDirAcc = FileAccessMgr::isExistFileOrDir(targetDir);
  EXPECT_EQ(newDirAcc.getFiletype(), FileType::DIR);

  // removedir が成功していること
  EXPECT_EQ(FileAccessMgr::removedir(targetDir), 1);

  // 対象ディレクトリが削除されており、存在しないこと
  FileAccessor dircheck2 = FileAccessMgr::isExistFileOrDir(targetDir);
  EXPCT_EQ(dircheck2.getFiletype, FileType::FILE_NOT_FOUND);
}

// 深いディレクトリを作成し、再帰的にデータを取得した後、ディレクトリを削除する
TEST(FileAccessMgr, getDirsRecursively_case1)
{
  const std::string TESTTMP_DIR("./debug");
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2"), true);
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/001"), true);
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/002"), true);
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/003"), true);
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/004"), true);
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/004/ab"), true);
  EXPECT_EQ(FileAccessMgr::makedir(TESTTMP_DIR + "/makedir_case2/004/cde"), true);

  // 一覧取得
  std::vector<FileAccessor> files = FileAccessMgr::getDirsRecursively("./debug");
  EXPECT_EQ(files.size(), 7); // 7 件のディレクトリが取得できている
  EXPECT_EQ(files[0].getFilePath(), TESTTMP_DIR + "/makedir_case2");
  EXPECT_EQ(files[1].getFilePath(), TESTTMP_DIR + "/makedir_case2/001");
  EXPECT_EQ(files[2].getFilePath(), TESTTMP_DIR + "/makedir_case2/002");
  EXPECT_EQ(files[3].getFilePath(), TESTTMP_DIR + "/makedir_case2/003");
  EXPECT_EQ(files[4].getFilePath(), TESTTMP_DIR + "/makedir_case2/004");
  EXPECT_EQ(files[5].getFilePath(), TESTTMP_DIR + "/makedir_case2/004/ab");
  EXPECT_EQ(files[6].getFilePath(), TESTTMP_DIR + "/makedir_case2/004/cde");

  // ディレクトリの削除(深いほうから削除)
}
