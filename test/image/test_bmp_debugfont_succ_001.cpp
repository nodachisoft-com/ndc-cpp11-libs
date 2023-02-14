#include <gtest/gtest.h>
#include <test_common/index.hpp>
#include "../../src/ndclibs.hpp"

using namespace nl;

// 新しく画像データを作成して、１文字を描画する
TEST(BitmapImage, writeChar_case001)
{
  BitmapImage image(50, 50);
  ColorRGB BASE_COLOR{0x00, 0xa0, 0x10}; // 緑っぽい
  image.clear(BASE_COLOR);

  ColorRGB COLOR_RED{0xff, 0x00, 0x00}; // 赤
  image.writeChar(10, 10, 'A', COLOR_RED);

  image.WriteBmp(TESTTMP_DIR + "test_writeChar_case001.bmp");
}
