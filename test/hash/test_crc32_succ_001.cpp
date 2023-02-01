#include <gtest/gtest.h>
#include "../../src/ndclibs.hpp"

// CRC32 コードが想定通りであること
TEST(Crc32, case1)
{
  Crc32 crc1, crc2;
  printf("%x\n", crc1.calcUpdateBytes((void *)"abcd", 4));

  char aa[] = "abcd";
  for (int i = 0; i < 4; i++)
  {
    crc2.calcUpdate(aa[i]);
  }

  // 計算結果確認
  char crc32Hash[8];
  sprintf(
      crc32Hash,
      "%x", crc2.getHash());
  EXPECT_EQ("ed82cd11", crc32Hash);
}

// １文字づつ読み取り方式で、結果が想定通りであること
TEST(Crc32, case2)
{
  Crc32 crc;
  char text[] = "abcd";
  for (int i = 0; i < 4; i++)
  {
    crc2.calcUpdate(text[i]);
  }
  // 計算結果確認
  char crc32Hash[8];
  sprintf(
      crc32Hash,
      "%x", crc2.getHash());
  EXPECT_EQ("ed82cd11", crc32Hash);
}
