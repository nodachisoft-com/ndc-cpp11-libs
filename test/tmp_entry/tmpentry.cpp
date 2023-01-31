// #include "../../src/ndclibs.hpp"
#include "../../src/image/index.hpp"

int main()
{
  BitmapImage bitmap("test/image/test_bmp_001.bmp");
  bitmap.WriteBmp("debug/copied.bmp");
}
