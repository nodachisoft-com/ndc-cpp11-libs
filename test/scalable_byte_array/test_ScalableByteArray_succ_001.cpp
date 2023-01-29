#include <gtest/gtest.h>
#include <string>
#include "../../src/scalable_byte_array/index.hpp"

TEST(ScalableByteArray, testcase1)
{
  ScalableByteArray *a = new ScalableByteArray(2);

  // INPUT
  a->append('A');
  a->append(123.456f);
  a->append(876);
  a->append('C');
  std::string msg("This is a test!");
  a->appendString(msg);

  // OUTPUT
  char out1;
  a->read(out1);
  printf("%c ", out1);

  float outFloat;
  a->read(outFloat);
  printf("%f ", outFloat);
  printf("%d ", a->readInt());
  printf("%c ", a->readChar());

  std::string msg_copy;
  msg_copy = a->readString(msg_copy);
  std::cout << "MSG=[" << msg_copy << "]" << std::endl;

  delete a;
  // EXPECT_EQ(3, 3);
}
