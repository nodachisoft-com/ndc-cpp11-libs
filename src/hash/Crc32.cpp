#include "Crc32.hpp"

Crc32::Crc32()
{
  generate_table();
}

void Crc32::generate_table()
{
  const unsigned long poly = 0xedb88320; // CRC-32-IEEE 802.3
  for (int i = 0; i < 256; i++)
  {
    unsigned long x = i;
    for (int j = 0; j < 8; j++)
    {
      unsigned long t = x & 1;
      x >>= 1;
      if (t)
        x ^= poly;
    }
    table[i] = x;
  }
}

unsigned long Crc32::calc(void *d, int len)
{
  unsigned char *c = (unsigned char *)d;
  unsigned long x = 0xffffffff;
  for (int i = 0; i < len; i++)
  {
    x = (x >> 8) ^ table[(x & 0xff) ^ c[i]];
  }
  return x ^ 0xffffffff;
}
