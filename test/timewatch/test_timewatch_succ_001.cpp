#include <gtest/gtest.h>
#include "../../src/ndclibs.hpp"

using namespace nl;

// 現在の時刻を取得する
TEST(TimeWatch, getNowMs_case001)
{
  int64_t nowUnixTimeMs = TimeWatch::getNowMs();
  // 想定されるような範囲に結果が含まれている。（2023/1/1～ 2123/1/1）
  EXPECT_TRUE((int64_t)1672498800 * 1000 < nowUnixTimeMs && nowUnixTimeMs < (int64_t)4828172400 * 1000L);
}

TEST(TimeWatch, getNowMsAsStrIso8601_case001)
{
  std::string time = TimeWatch::getNowMsAsStrIso8601();
  EXPECT_EQ(time.size(), 25);
}

TEST(TimeWatch, getNowMsAsStr_hhmmssSSS_case001)
{
  std::string time = TimeWatch::getNowMsAsStr_hhmmssSSS();
  EXPECT_EQ(time.size(), 12);
}
