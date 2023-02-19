#pragma once
#include <vector>
#include <iostream>
#include <regex>
#include "../timewatch/index.hpp"

namespace nl
{
  class Logger
  {
    // 出力するログレベルに対応
    // constexpr outputLv = 1; // 0: DEBUG, 1:INFO, 2:ERROR

  private:
    bool isOutputToConsole;
    bool isOutputToFile;
    bool isFiltered;
    std::regex filterCondition;

    void outputToConsole(const std::string &msg, const std::string &logLevel)
    {
      // フィルタ機能は有効であるか判定
      if (isFiltered)
      {

        // フィルタ条件に合致しない場合は出力しない
        if (!isFilterTarget(msg))
        {
          return;
        }
      }

      if (isOutputToConsole)
      {
        std::string timestamp = TimeWatch::getNowMsAsStr_hhmmssSSS();
        std::cout << "[" << logLevel << " " << timestamp << "] " << msg << std::endl;
      }
    }

    void outputToFile(const std::string &msg, const std::string &logLevel)
    {
      // TODO: ファイルへの非同期出力をここに記述
    }

    /// @brief フィルタが ON であり、フィルタ対象かを判定する
    /// @param msg フィルタ確認する対象文字列
    /// @return フィルタ対象であれば true、対象外であれば false を返す
    bool isFilterTarget(const std::string &msg)
    {
      return (std::regex_match(msg, filterCondition));
    }

    // エスケープシーケンスを標準出力する
    void escSeq(char const *controlSequence, char const function)
    {
      printf("\x1B[");
      printf(controlSequence);
      putchar(function);
    }

    // RGB を指定して文字の色を変更する
    void setFontColorRGB(const unsigned char r, const unsigned char g, const unsigned char b)
    {
      char buf[64];
      sprintf(buf, "38;2;%d;%d;%d", r, g, b);
      escSeq(buf, 'm');
    }

    void resetColor()
    { // 色情報をリセット
      escSeq("0", 'm');
    }

  public:
    Logger();
    Logger(std::string filepath);
    ~Logger();

    /// @brief 指定した文字にログのメッセージ部が部分一致した時のみ出力対象とする
    /// @param substr 部分一致チェック文字列
    void doFilter(const std::string substr);

    /// @brief 部分一致用のフィルタを解除する
    void removeFilter();

    void debugLog(const std::string &msg);
    void infoLog(const std::string &msg);
    void errorLog(const std::string &msg);
  };
}
