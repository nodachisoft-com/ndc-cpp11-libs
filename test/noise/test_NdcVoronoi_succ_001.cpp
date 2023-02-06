#include <gtest/gtest.h>
#include <test_common/index.hpp>
#include <math.h>
#include "../../src/ndclibs.hpp"

// Voronoi 図形で 64 x 64 画像を生成する
TEST(NdcVoronoi, genMap_case001)
{
  int width = 32, height = 32;
  int noisePx = 4, noisePy = 4;
  unsigned char typeRange = 3;
  long randomSeed = 100;
  BitmapImage image(width, height);
  ColorRGB colorTable[4] = {
      {200, 0, 0}, {0, 200, 0}, {0, 0, 200}, {200, 200, 0}};

  NdcVoronoi voro(randomSeed, typeRange, noisePx, noisePy);

  Crc32 crc;
  for (int v = 0; v < width; v++)
  {
    for (int u = 0; u < height; u++)
    {
      unsigned char res = voro.pos2((float)v * noisePx / (float)width, (float)u * noisePy / (float)height);
      crc.calcUpdate(res);
      image.set(u, v, colorTable[res]);
    }
  }
  image.WriteBmp(TESTTMP_DIR + "genMap_case001.bmp");

  EXPECT_EQ(crc.getHash(), 3894535006); // データ本体部の CRC32
}
