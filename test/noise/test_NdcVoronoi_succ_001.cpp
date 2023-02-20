#include <gtest/gtest.h>
#include <test_common/index.hpp>
#include <math.h>
#include <string>
#include "../../src/ndclibs.hpp"

using namespace nl;

// Voronoi 図形で画像を生成し、CRC32 チェックを行う
TEST(NdcVoronoi, genMap_case001)
{
  std::string path(TESTTMP_DIR + "genMap_case001.bmp");
  int width = 640, height = 640;
  int noisePx = 4, noisePy = 4;
  unsigned char typeRange = 3;
  long randomSeed = 100;
  BitmapImage image(width, height);
  ColorRGB colorTable[4] = {
      {200, 0, 0}, {0, 200, 0}, {0, 0, 200}, {200, 200, 0}};

  NdcVoronoi voro(randomSeed, typeRange, noisePx, noisePy);

  Crc32 crc;
  for (int v = 0; v < height; v++)
  {
    for (int u = 0; u < width; u++)
    {
      unsigned char res = voro.pos2(u * noisePx / (float)width, v * noisePy / (float)height);
      crc.calcUpdate(res);
      image.set(u, v, colorTable[res]);
    }
  }
  image.WriteBmp(path);
  EXPECT_EQ(crc.getHash(), 161513028); // データ本体部の CRC32
}

// Voronoi 図形で生成点の多い画像を生成し、CRC32 チェックを行う
TEST(NdcVoronoi, genMap_case002)
{
  std::string path(TESTTMP_DIR + "genMap_case002.bmp");
  int width = 100, height = 100;
  int noisePx = 100, noisePy = 100;
  unsigned char typeRange = 3;
  long randomSeed = 101;
  BitmapImage image(width, height);
  ColorRGB colorTable[4] = {
      {200, 0, 0}, {0, 200, 0}, {0, 0, 200}, {200, 200, 0}};

  // TODO: MemoryBank に突っ込んで diff を撮る！
  MemoryBank memo;
  NdcVoronoi voro(randomSeed, typeRange, noisePx, noisePy);
  Crc32 crc;
  for (int v = 0; v < height; v++)
  {
    for (int u = 0; u < width; u++)
    {
      unsigned char res = voro.pos2(u * noisePx / (float)width, v * noisePy / (float)height);
      crc.calcUpdate(res);
      image.set(u, v, colorTable[res]);
      memo.appendByte(res);
    }
  }
  EXPECT_EQ(crc.getHash(), 2004865003); // データ本体部の CRC32

  FileAccessor fa("voronoi_test_diff1.txt");
  fa.setMemoryBank(&memo);
  fa.writeFileSync();
  image.WriteBmp(path);
}

// Voronoi 初期化での挙動確認
TEST(NdcVoronoi, genMap_case003)
{
  NdcVoronoi v1(100, 4, 32, 32);
  EXPECT_EQ(v1.init(50, 4, 5, 5), false);   // 改めて init（初期化済みなので false）
  EXPECT_EQ(v1.init(51, 5, 15, 15), false); // 再度 init（初期化済みなので false）

  // デフォルトコンストラクタ使用
  NdcVoronoi v2;
  EXPECT_EQ(v2.init(50, 4, 5, 5), true);    // 改めて init（初期化未済なので true）
  EXPECT_EQ(v2.init(51, 5, 15, 15), false); // 再度 init（初期化済みなので false）
}
