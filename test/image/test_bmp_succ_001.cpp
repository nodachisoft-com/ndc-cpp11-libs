#include <gtest/gtest.h>
#include <test_common/index.hpp>
#include "../../src/ndclibs.hpp"

// 新しく画像データを作成し、左上に赤い横線を引く
TEST(BitmapImage, case1)
{
  BitmapImage image(16, 16);
  for (int i = 0; i < 5; i++)
  {
    ColorRGB COLOR_RED{0xff, 0x00, 0x00};
    image.set(i, 2, COLOR_RED);
  }
  image.WriteBmp(TESTTMP_DIR + "test_BitmapImage_case1.bmp");

  // TODO: 正解ファイルとの HASH 値比較
}

// 画像データを読み込み、別ファイルに出力する
TEST(BitmapImage, case2)
{
  BitmapImage image("test/image/test_bmp_001.bmp");
  image.WriteBmp("test_BitmapImage_case2.bmp");
}
