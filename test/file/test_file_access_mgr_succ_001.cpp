#include <gtest/gtest.h>
#include "../../src/ndclibs.hpp"

#include <string>

// カレントディレクトリのパスを取得する
TEST(FileAccessMgr, case1)
{
  std::string curDir(FileAccessMgr::getCurDir());
  std::cout << "Current Dir=" << curDir << std::endl;
}
