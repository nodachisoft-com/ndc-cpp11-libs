#pragma once

#include <stdint.h>

class Crc32
{
private:
  unsigned long table[256];
  unsigned long hash;

  void generate_table();

public:
  Crc32();

  unsigned long calcUpdateBytes(void *d, int len);
  void calcUpdate(char c);
  unsigned long getHash();
};
