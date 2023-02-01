#pragma once

#include <stdint.h>

class Crc32
{
private:
  unsigned long table[256];

  void generate_table();

public:
  Crc32();

  unsigned long calc(void *d, int len);
};
