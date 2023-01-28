#pragma once
#include <vector>

class SerializeBuffer
{
  std::vector<char> buffer;
  long readoffset;
  SerializeBuffer();
  SerializeBuffer *append(bool v);
  SerializeBuffer *append(byte v);
  SerializeBuffer *append(short v);
  SerializeBuffer *append(long v);
  SerializeBuffer *append(float v);
  SerializeBuffer *append(double v);
  bool readBool();
  Byte readByte();
  short readShort();
  long readLong();
  float readFloat();
  double readDouble();
}
