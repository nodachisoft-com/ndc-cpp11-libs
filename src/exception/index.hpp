#pragma once
#include <string>

/**
 * 基底の例外クラス
 */
class NdcBaseException : public std::exception
{
public:
  NdcBaseException(const std::string &msg);
  char const *what() const noexcept;

private:
  std::string message;
};

/**
 * メモリ確保失敗時のエラー
 */
class OutOfMemoryException : public NdcBaseException
{
  using NdcBaseException::NdcBaseException;
};

/**
 * 範囲外のメモリアドレスへのアクセスが支持された場合に発生する例外
 */
class OutOfRangeAccessException : public NdcBaseException
{
  using NdcBaseException::NdcBaseException;
};
