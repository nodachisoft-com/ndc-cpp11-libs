#include <gtest/gtest.h>
#include "../../src/ndclibs.hpp"

using namespace nl;

// 各種ログレベルが正しく出力されること
TEST(Logger, case1)
{
  Logger logger;
  logger.doFilter("aaa");
  // logger.debugLog("this is a test DEBUG log!");
  // logger.infoLog("this is a test INFO log!");
  // logger.infoLog("this is a test INFO log!aaabbbccc");
  // logger.errorLog("this is a test ERROR log!");
  // logger.errorLog("this is a test ERROR logddddd!aaagggg");
  // logger.debugLog("this is a filter test aaa desu!!");
}
