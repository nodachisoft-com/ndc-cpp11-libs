#pragma once

template <class T>
class Memory1d
{
  T *buf;
  T outOfRangeData;

public:
  Memory1d(int width)
  {
    buf = new T(width);
  }
  ~Memory1d()
  {
    delete buf;
  }
  void setOutOtRangeData(T t)
  {
    outOfRangeData = t;
  }
  bool setWithIgnoreOutOfRangeData(int x)
  {
    return true;
  }
  T getWithIgnoreOutOfRangeData(int x)
  {
    return buf[0];
  }
}
