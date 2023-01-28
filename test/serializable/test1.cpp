#include <gtest/gtest.h>
#include "../../src/serializable/ISerializable.hpp"

/*
class TestData : public ISerializable
{
  TestData();
  ostream serialize(ostream data)
  {
  }
  void deserialize(ostream data)
  {
  }
};
*/

TEST(test1, testcase1)
{
  std::vector<uint8_t> data;
  EXPECT_EQ(3, 3);
}
