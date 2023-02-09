#include <gtest/gtest.h>
#include "../../src/ndclibs.hpp"

// 各種 append と read が正しく動作すること
TEST(Memory1d, succ001)
{
  Memory1d<int> mem(100);

  // EXPECT_EQ(485967120, crc.getHash());
}
