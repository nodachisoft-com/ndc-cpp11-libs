#include <gtest/gtest.h>
#include "../../src/random/index.hpp"

TEST(random, case1)
{
  Randomizer *r = RandomProvider::getRandomizer(RND_TYPE::MT19937, 100);
  for (int i = 0; i < 10000; i++)
  {
    std::cout << r->getRndInt(0, 3) << ",";
  }
  EXPECT_EQ(3, 3);
}
