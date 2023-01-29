#include <gtest/gtest.h>
#include "../../src/scalable_byte_array/index.hpp"

TEST(ScalableByteArray, testcase1)
{
  // ScalableByteArray *a = new ScalableByteArray();
  // a->debug();
  ScalableByteArray *a = new ScalableByteArray(2);
  a->debug();
  a->append('A');
  a->debug();
  a->append('B');
  a->debug();
  a->append('C');
  a->debug();
  a->append('1')->append('2')->append('3');

  int size = a->getUsingSize();
  for (int i = 0; i < size; i++)
  {
    printf("%c", a->get(i));
  }

  // EXPECT_EQ(3, 3);
}
