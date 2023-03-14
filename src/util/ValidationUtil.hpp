#pragma once
#include <string>
#include <regex>

namespace nl
{
  namespace util
  {
    namespace _inner
    {
      // ±記号を表記可能な数字であることを判別すr
      static const std::regex RegNumber(R"([\+\-]?[0-9]+)");
    }

    template <class T>
    static inline bool isBetweenNotEq(const T min, const T max, const T checkVal)
    {
      return (min < checkVal && checkVal < max) ? true : false;
    }

    template <class T>
    static inline bool isBetweenEq(const T min, const T max, const T checkVal)
    {
      return (min <= checkVal && checkVal <= max) ? true : false;
    }

    static inline bool isInt(const std::string str)
    {
      return std::regex_match(str, _inner::RegNumber);
    }
  }
}
