#include "../../src/ndclibs.hpp"
// #include "../../src/image/index.hpp"

int main()
{
  Crc32 crc1, crc2;
  printf("%lx\n", crc1.calcUpdateBytes((void *)"abcd", 4));

  char aa[] = "abcd";
  for (int i = 0; i < 4; i++)
  {
    crc2.calcUpdate(aa[i]);
  }
  printf("%lx\n", crc2.getHash());

  char crc32Hash[8];
  sprintf(
      crc32Hash,
      "%lx", crc2.getHash());

  printf("RE=%s", crc32Hash);
}
