#include <gtest/gtest.h>
#include "../../src/ndclibs.hpp"

// １次元で確保したメモリのサイズを取得する
TEST(Memory1d, size_succ001)
{
  Memory1d<int> mem(123, 4);
  mem.setOutOfRangeData(-1);
  EXPECT_EQ(123, mem.size());
}

// １次元で確保したメモリに getWithIgnoreOutOfRangeData を行い
// 範囲外を指定した時に OutOfRangeData で設定した値が返ること
// 範囲内を指定した時に 初期化で指定した値が返ること
TEST(Memory1d, getWithIgnoreOutOfRangeData_succ001)
{
  Memory1d<int> mem(123, 4);
  mem.setOutOfRangeData(-1);
  EXPECT_EQ(-1, mem.getWithIgnoreOutOfRangeData(999));
  EXPECT_EQ(-1, mem.getWithIgnoreOutOfRangeData(-1));
  EXPECT_EQ(4, mem.getWithIgnoreOutOfRangeData(1));
}

// １次元で確保したメモリに setWithIgnoreOutOfRangeData で値をセット
// 範囲内の setWithIgnoreOutOfRangeData で true が返ること
// 範囲外の setWithIgnoreOutOfRangeData で false が返ること
TEST(Memory1d, setWithIgnoreOutOfRangeData_succ001)
{
  Memory1d<int> mem(5000, 0);
  mem.setOutOfRangeData(-1);
  bool setResult = true;
  for (int i = 0; i < 5000; i++)
  {
    if (mem.setWithIgnoreOutOfRangeData(i, i) == false)
    {
      // 失敗した場合
      setResult = false;
    }
  }

  EXPECT_EQ(setResult, true);

  // 範囲外に set しようとして false が返る
  EXPECT_EQ(mem.setWithIgnoreOutOfRangeData(-5, 100), false);
  EXPECT_EQ(mem.setWithIgnoreOutOfRangeData(5000, 111), false);
}

TEST(Memory1d, getDataPerodic_succ001)
{
  Memory1d<int> mem(3, 0);
  for (int i = 0; i < 3; i++)
  {
    mem.setWithIgnoreOutOfRangeData(i, i);
  }

  // 通常の範囲内
  EXPECT_EQ(mem.getDataPerodic(0), 0);
  EXPECT_EQ(mem.getDataPerodic(1), 1);
  EXPECT_EQ(mem.getDataPerodic(2), 2);

  // 正の方向で範囲を超過している
  EXPECT_EQ(mem.getDataPerodic(3), 0);
  EXPECT_EQ(mem.getDataPerodic(4), 1);
  EXPECT_EQ(mem.getDataPerodic(5), 2);

  // 正の方向で範囲を超過している（２週目）
  EXPECT_EQ(mem.getDataPerodic(6), 0);
  EXPECT_EQ(mem.getDataPerodic(7), 1);
  EXPECT_EQ(mem.getDataPerodic(8), 2);

  // 負の方向で範囲を超過している
  EXPECT_EQ(mem.getDataPerodic(-1), 2);
  EXPECT_EQ(mem.getDataPerodic(-2), 1);
  EXPECT_EQ(mem.getDataPerodic(-3), 0);

  // 負の方向で範囲を超過している（２週目）
  EXPECT_EQ(mem.getDataPerodic(-4), 2);
  EXPECT_EQ(mem.getDataPerodic(-5), 1);
  EXPECT_EQ(mem.getDataPerodic(-6), 0);
}

// ループ状態でデータをセットできることを確認する
TEST(Memory1d, setDataPerodic_succ001)
{
  Memory1d<int> mem(3, 0);

  bool isExpected = true;

  for (int i = -30; i < 30; i++)
  {
    mem.setDataPerodic(i, i);
    if (mem.getDataPerodic(i) != i)
    {
      isExpected = false;
    }
  }
  EXPECT_EQ(isExpected, true);
}
