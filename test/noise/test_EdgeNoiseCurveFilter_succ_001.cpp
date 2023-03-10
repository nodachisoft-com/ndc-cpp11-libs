#include <gtest/gtest.h>
#include <test_common/index.hpp>
#include <math.h>
#include <string>
#include "../../src/ndclibs.hpp"

using namespace nl;

// Edge Noise 図形で画像を生成し、CRC32 チェックを行う
TEST(EdgeNoiseCurveFilter, pos2_case001)
{

  int width = 640, height = 640;
  float edgeWide = 0.3f;
  BitmapImage image(width, height);
  EdgeNoiseCurveFilter filter(edgeWide);

  Crc32 crc;
  for (int v = 0; v < height; v++)
  {
    for (int u = 0; u < width; u++)
    {
      unsigned char h = (unsigned char)(255.0f * filter.pos2(u / (float)width, v / (float)height));
      crc.calcUpdate(h);
      ColorRGB color{h, h, h};
      image.set(u, v, color);
    }
  }
  std::string path(TESTTMP_DIR + "EdgeNoiseCurveFilter_pos2_case001.bmp");
  image.WriteBmp(path);
  // EXPECT_EQ(crc.getHash(), 161513028); // データ本体部の CRC32
}
