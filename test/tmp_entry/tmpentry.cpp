#include "../../src/ndclibs.hpp"
// #include "../../src/image/index.hpp"

int main()
{
  // BitmapImage image("test/image/test_bmp_001.bmp");
  // bitmap.WriteBmp("debug/copied.bmp");
  BitmapImage image(219, 110);
  for (int i = 0; i < 100; i++)
  {
    ColorRGB c;
    c.r = 0xf0;
    c.g = 0x00;
    c.b = 0x00;
    image.set(i, i, c);
  }
  image.WriteBmp("debug/ttt.bmp");

  // PerlinNoise1234::pnoise2()
}
