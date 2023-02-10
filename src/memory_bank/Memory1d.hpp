#pragma once
#include "../exception/index.hpp"

template <class T>
class Memory1d
{
  T *buf;
  T outOfRangeData;
  int width;

public:
  Memory1d(const int _width, const T initialValue)
  {
    try
    {
      buf = new T[_width];
      width = _width;
    }
    catch (std::bad_alloc &ex)
    {
      std::string msg("Memory1d: Failed To Allocate Memory!");
      throw OutOfMemoryException(msg);
    }
    // 初期化
    for (int i = 0; i < _width; i++)
    {
      buf[i] = initialValue;
    }
  }
  ~Memory1d()
  {
    delete[] buf;
  }
  int size()
  {
    return width;
  }

  void setOutOfRangeData(const T t)
  {
    outOfRangeData = t;
  }
  bool setWithIgnoreOutOfRangeData(const int x, const T val)
  {
    if (x < 0 || width <= x)
    {
      return false;
    }
    buf[x] = val;
    return true;
  }
  T getWithIgnoreOutOfRangeData(const int x)
  {
    if (x < 0 || width <= x)
    {
      return outOfRangeData;
    }
    return buf[x];
  }

  /// @brief
  ///   位置 x に対してループとなるように要素を返す
  ///   例 データ列 [3,4,5] => 3, 4, 5, 3, 4, 5 ... と結果が返る
  /// @param x 取得する要素の位置
  /// @return 取得した要素
  T getDataPerodic(const int x)
  {
    if (x < 0)
    {
      return buf[width - (-x % width)];
    }
    return buf[x % width];
  }

  /// @brief
  ///  位置 x に対してループとなるよう要素番号を射影して値をセットする
  /// @param x 設定する要素の位置
  /// @param value 設定する値
  void setDataPerodic(const int x, const T value)
  {
    if (x < 0)
    {
      buf[width - (-x % width)] = value;
    }
    else
    {
      buf[x % width] = value;
    }
  }

  void writeMemory1dWithTrimOutOfRange(const Memory1d<T> &src, const int srcBeginX, const int copyLength, const int destBeginX)
  {
    if (srcBeginX < 0 || srcBeginX + copyLength > src.width)
    {
      // コピー元が範囲外である
      std::string msg(typeid(*this).name());
      msg += ":out of range.";
      throw ArgumentValidatioinException(msg);
    }

    for (int i = 0; i < copyLength && i + destBeginX < width; i++)
    {
      buf[i + destBeginX] = src.buf[i + srcBeginX];
    }
  }

  void writeMemory1dWithPerodicOutOfRange(const Memory1d<T> &src, const int srcBeginX, const int copyLength, const int destBeginX)
  {
    if (srcBeginX < 0)
    {
      // コピー元が範囲外である
      std::string msg(typeid(*this).name());
      msg += ":out of range.";
      throw ArgumentValidatioinException(msg);
    }

    for (int i = 0; i < copyLength; i++)
    {
      buf[(i + destBeginX) % width] = src.buf[i + srcBeginX];
    }
  }
};
