#include <gtest/gtest.h>
#include <test_common/index.hpp>
#include <math.h>
#include "../../src/ndclibs.hpp"

using namespace nl;

// PerlinNoise で同じ位置で同じ結果が得られるかの確認を行う
TEST(PerlinNoise1234, MT19937_HF_case001)
{
  std::ostringstream oss;
  PerlinNoise1234 pn(100);
  float sum = 0.0f;
  bool equalFlag = true;
  for (int u = 0; u < 256; u++)
  {
    float memory = pn.pnoise2(u / 6.0f, u * 1.03f / 4.0f, 6, 6, 255.0f);
    for (int tryCount = 0; tryCount < 3; tryCount++)
    {
      if (memory != pn.pnoise2(u / 6.0f, u * 1.03f / 4.0f, 6, 6, 255.0f))
      {
        equalFlag = false;
      }
    }
    sum += memory;
  }
  oss << std::fixed << std::setprecision(5) << sum;
  EXPECT_EQ(oss.str(), "32438.62891");
  EXPECT_EQ(equalFlag, true);
}

// PPN で再現可能な HeightField 画像を生成し、CRC32 でチェックする
TEST(PerlinNoise1234, MT19937_HF_case002)
{
  int width = 70;
  int height = 46;
  BitmapImage image(width, height);
  PerlinNoise1234 pn(100);
  int noisePointX = 8;
  int noisePointY = 8;

  Crc32 crc;
  for (int v = 0; v < height; v++)
  {
    for (int u = 0; u < width; u++)
    {
      float res = pn.pnoise2((u * noisePointX) / (float)width, (v * noisePointY) / (float)height, noisePointX, noisePointY, 255.0f);
      unsigned char color_elem = (unsigned char)res;
      crc.calcUpdate(color_elem);
      ColorRGB color{color_elem, color_elem, color_elem};
      image.set(u, v, color);
    }
  }
  image.WriteBmp(TESTTMP_DIR + "MT19937_HF_case002.bmp");

  // CRC32 を取得する
  FileAccessor fa(TESTTMP_DIR + "MT19937_HF_case002.bmp");
  EXPECT_EQ(fa.readFileSync(), true);
  EXPECT_EQ(fa.getFilesize(), 9806);
  EXPECT_EQ(fa.calcMemoryCrc32(), 278549108); // BITMAP 構造体 + データ本体
  EXPECT_EQ(crc.getHash(), 2085138398);       // データ本体のみの CRC32
}
