#pragma once
#include "../ndclibs.hpp"

class SerializeBuffer
{
private:
  std::vector<char> buffer;
  long readoffset;

public:
  SerializeBuffer();

  void setOffsetToHead();

  SerializeBuffer *appendInt(int v);
  int readInt();

  SerializeBuffer *appendFloat(float v);
  float readFloat();
};
