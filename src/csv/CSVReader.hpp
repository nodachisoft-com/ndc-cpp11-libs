#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "../exception/index.hpp"

namespace nl
{
  class CSVReader
  {
  public:
    /// @brief CSV データ読み込み時のデリミタやエスケープコードの設定を行う
    /// @param delimiter CSV のデリミタ指定
    /// @param escape_char CSV セル内のエスケープコード
    CSVReader(char delimiter, char escape_char) : delimiter_(delimiter), escape_char_(escape_char) {}

    /// @brief 2次元の文字列データ
    /// @param csv_data 読み込む CSVデータ
    /// @return
    void readCsv(const std::string &csv_data);

    /// @brief 指定したセルデータを読み取る。範囲外の場合は OutOfRangeAccessException 例外を返す
    /// @param col 列方向（x方向）の指定
    /// @param row 行方向（y方向）の指定
    /// @return 指定したセルデータの文字列
    std::string getCell(int col, int row);

  private:
    /// @brief 読み込み後のデータ
    std::vector<std::vector<std::string>> data;

    /// @brief デリミタ
    char delimiter_;

    /// @brief エスケープコード
    char escape_char_;
  };
}
