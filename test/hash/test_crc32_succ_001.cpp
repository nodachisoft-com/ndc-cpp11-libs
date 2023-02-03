#include <gtest/gtest.h>
#include "../../src/ndclibs.hpp"

// CRC32 コードが想定通りであること
TEST(Crc32, case1)
{
  Crc32 crc;
  std::string text("abcd");
  unsigned long result = crc.calcUpdateBytes((void *)text.c_str(), text.length());

  // 計算結果確認
  EXPECT_EQ(3984772369, result);
  EXPECT_EQ(3984772369, crc.getHash());
}

// １文字づつ読み取り方式で、結果が想定通りであること
TEST(Crc32, case2)
{
  Crc32 crc;
  char text[] = "abcd";
  for (int i = 0; i < 4; i++)
  {
    crc.calcUpdate(text[i]);
  }
  EXPECT_EQ(3984772369, crc.getHash());
}
