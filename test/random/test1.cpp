#include <gtest/gtest.h>
#include "../../src/random/index.hpp"

// 整数で[0,10]の範囲で 10,000 回乱数取得し、
// 生成された値の偏りが 1 割以上の差となっていないことを
// 確認する
TEST(random, case1)
{
  Randomizer *r = RandomProvider::getRandomizer(RND_TYPE::MT19937, 100);
  int c[10] = {};
  for (int i = 0; i < 10000; i++)
  {
    int randnum = r->getRndInt(0, 9);
    c[randnum]++;
  }
  for (int i = 0; i < 10; i++)
  {
    int d = c[i];
    int lookfor = 10000 / 10;
    if (d <= 0.9f * lookfor || lookfor * 1.1f <= d)
    {
      // 確率ばらけすぎでは
      ASSERT_TRUE(false);
    }
  }
};

// [5,8] の範囲で正しく取得可能なこと
TEST(random, case2)
{
  Randomizer *r = RandomProvider::getRandomizer(RND_TYPE::MT19937, 100);
  int min = INT32_MAX;
  int max = INT32_MIN;
  for (int i = 0; i < 1000; i++)
  {
    int rnd = r->getRndInt(5, 8);
    if (rnd < min)
    {
      min = rnd;
    }
    if (rnd > max)
    {
      max = rnd;
    }
  }
  EXPECT_EQ(min, 5);
  EXPECT_EQ(max, 8);
};

// シリアライズ・デシリアライズ処理が正しく動作することを確認する
