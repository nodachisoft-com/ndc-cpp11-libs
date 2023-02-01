#include "../../src/ndclibs.hpp"
// #include "../../src/image/index.hpp"

int main()
{
  Crc32 crc;
  printf("%x\n", crc.calc((void *)"abcd", 4));
}
