#include <gtest/gtest.h>
#include "../../src/scalable_byte_array/index.hpp"

TEST(ScalableByteArray, testcase1)
{
  // ScalableByteArray *a = new ScalableByteArray();
  // a->debug();
  ScalableByteArray *a = new ScalableByteArray(2);
  a->append('A');
  a->append(123.456f);
  a->append(876);
  a->append('C');

  printf("%c ", a->readChar());
  printf("%f ", a->readFloat());
  printf("%d ", a->readInt());
  printf("%c ", a->readChar());

  // EXPECT_EQ(3, 3);
}
