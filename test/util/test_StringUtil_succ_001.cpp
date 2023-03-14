#include <gtest/gtest.h>
#include "../../src/ndclibs.hpp"

using namespace nl;

TEST(util, isBetweenNotEq_case001)
{
  EXPECT_EQ(util::isBetweenNotEq<int>(0, 2, 1), true);
  EXPECT_EQ(util::isBetweenNotEq<int>(0, 2, 2), false);
  EXPECT_EQ(util::isBetweenNotEq<int>(0, 2, 0), false);
  EXPECT_EQ(util::isBetweenNotEq<int>(1, 2, 0), false);
}

TEST(util, isBetweenEq_case001)
{
  EXPECT_EQ(util::isBetweenEq<int>(0, 2, 1), true);
  EXPECT_EQ(util::isBetweenEq<int>(0, 2, 2), true);
  EXPECT_EQ(util::isBetweenEq<int>(0, 2, 0), true);
  EXPECT_EQ(util::isBetweenEq<int>(1, 2, 0), false);
}

// isInt のパターン確認
TEST(util, isInt_case001)
{
  EXPECT_EQ(util::isInt("+"), false);
  EXPECT_EQ(util::isInt("-"), false);
  EXPECT_EQ(util::isInt("a"), false);
  EXPECT_EQ(util::isInt("A"), false);
  EXPECT_EQ(util::isInt("."), false);
  EXPECT_EQ(util::isInt("0"), true);
  EXPECT_EQ(util::isInt("9"), true);
  EXPECT_EQ(util::isInt("+0"), true);
  EXPECT_EQ(util::isInt("-0"), true);
  EXPECT_EQ(util::isInt("12"), true);
  EXPECT_EQ(util::isInt("1."), false);
  EXPECT_EQ(util::isInt(".1"), false);
  EXPECT_EQ(util::isInt("+100"), true);
  EXPECT_EQ(util::isInt("-100"), true);
  EXPECT_EQ(util::isInt("--100"), false);
  EXPECT_EQ(util::isInt("++100"), false);
  EXPECT_EQ(util::isInt("100+1"), false);
  EXPECT_EQ(util::isInt("100-1"), false);
}
