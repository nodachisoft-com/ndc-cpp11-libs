#pragma once
#include "../exception/index.hpp"

template <class T>
class Memory1d
{
  T *buf = NULL;
  T outOfRangeData;

  /// @brief 他の Memory1d データで上書きする際に、特定のデータを無視するか
  bool isMaskConditionEnable = false;

  /// @brief 無視するデータ定義。isMaskConditionEnable が true なら読み取られる
  T maskConditionData;
  int width;

public:
  Memory1d(const int _width, const T initialValue)
  {
    resizeMemory(_width);
    setWholeData(initialValue);
  }

  void resizeMemory(const int _width)
  {
    if (buf != NULL)
    {
      // 初回の初期化以外では前回確保分のメモリ削除を行う
      delete[] buf;
    }

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
  }

  void setWholeData(const T initialValue)
  {
    // 初期化
    for (int i = 0; i < width; i++)
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

  /// @brief ほかの Memory1d データで上書きする際に、無視するデータを指定
  /// @param t 無視する対象のデータ
  void setMaskConditionWhenWriteMemory(const T t)
  {
    maskConditionData = t;
  }

  void setEnableMaskCondition(const T mask)
  {
    isMaskConditionEnable = true;
    maskConditionData = mask;
  }

  void setDisableMaskCondition()
  {
    isMaskConditionEnable = false;
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
      if (isMaskConditionEnable)
      {
        if (maskConditionData == src.buf[i + srcBeginX])
        {
          // データが無視する対象と合致するため、上書き処理を行わない
          continue;
        }
      }
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
      if (isMaskConditionEnable)
      {
        if (maskConditionData == src.buf[i + srcBeginX])
        {
          // データが無視する対象と合致するため、上書き処理を行わない
          continue;
        }
      }
      buf[(i + destBeginX) % width] = src.buf[i + srcBeginX];
    }
  }

  /// @brief TODO: copyTo で引数内容を直接編集するのではなく、
  ///   スマートポインタで new した結果を返すのが望ましい。
  /// @param from
  /// @param to
  /// @param copyTo
  void getCopyRange(const int from, const int to, Memory1d<T> &copyTo)
  {
    if (0 > from || width <= to || from > to)
    {
      // コピー元が範囲外である
      std::string msg(typeid(*this).name());
      msg += ":out of range.";
      throw ArgumentValidatioinException(msg);
    }
    int newWidth = to - from;
    copyTo.resizeMemory(newWidth);
    for (int i = 0; i < newWidth; i++)
    {
      copyTo.setWithIgnoreOutOfRangeData(i, buf[from + i]);
    }
  }
};
