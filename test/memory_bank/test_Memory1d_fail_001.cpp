#include <gtest/gtest.h>
#include "../../src/ndclibs.hpp"

using namespace nl;

// メモリ確保に失敗するケース。(int) * 2000M 程度 = 8TB サイズの確保を試みる
TEST(Memory1d, fail001)
{
  bool exceptionFlag = false;
  try
  {
    Memory1d<int> mem(0x7fffffff, 4);
  }
  catch (OutOfMemoryException &ex)
  {
    exceptionFlag = true;
  }

  EXPECT_EQ(true, exceptionFlag);
}
