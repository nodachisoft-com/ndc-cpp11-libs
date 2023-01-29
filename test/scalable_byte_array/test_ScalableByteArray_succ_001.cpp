#include <gtest/gtest.h>
#include "../../src/scalable_byte_array/index.hpp"

TEST(ScalableByteArray, testcase1)
{
  // ScalableByteArray *a = new ScalableByteArray();
  // a->debug();
  ScalableByteArray *a = new ScalableByteArray(2);
  a->append('A');
  a->append('B');
  a->append(876);
  a->append('C');

  printf("%c", a->readChar());
  printf("%c", a->readChar());
  printf("%d", a->readInt());
  printf("%c", a->readChar());

  // EXPECT_EQ(3, 3);
}
