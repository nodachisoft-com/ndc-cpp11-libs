/**
 * @brief 例外機能をまとめて提供するためのヘッダ
 */
#pragma once
#include "../ndclibs.hpp"

/// @brief
///  アプリ基盤の基底の例外クラス。
///  エラーメッセージを所持する。
class NdcBaseException : public std::exception
{
public:
  /// @brief コンストラクタ。例外内容のエラーコードなどを渡す
  /// @param[in] msg エラーコードなどの例外内容に紐づく文字列
  NdcBaseException(const std::string &msg);

  /// @brief メッセージ内容を取得する
  /// @return メッセージ内容の文字列へのポインタ
  char const *what() const noexcept;

private:
  /// @brief エラーコードなどの例外内容に紐づく文字列
  std::string message;
};

/// @brief メモリ確保失敗時に発生する例外
class OutOfMemoryException : public NdcBaseException
{
  using NdcBaseException::NdcBaseException;
};

/// @brief 範囲外のメモリアドレスへのアクセスが指示された場合に発生する例外
class OutOfRangeAccessException : public NdcBaseException
{
  using NdcBaseException::NdcBaseException;
};
