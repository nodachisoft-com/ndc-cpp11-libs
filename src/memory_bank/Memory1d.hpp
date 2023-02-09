#pragma once

template <class T>
class Memory1d
{
  T *buf;
  T outOfRangeData;
  int width;

public:
  Memory1d(int _width)
  {
    buf = new T(_width);
    width = _width;
  }
  ~Memory1d()
  {
    delete buf;
  }
  void setOutOtRangeData(T t)
  {
    outOfRangeData = t;
  }
  bool setWithIgnoreOutOfRangeData(int x, T val)
  {
    if (x < 0 || width <= x)
    {
      return false;
    }
    buf[x] = val;
    return true;
  }
  T getWithIgnoreOutOfRangeData(int x)
  {
    if (x < 0 || width <= x)
    {
      return outOfRangeData;
    }
    return buf[x];
  }
};
