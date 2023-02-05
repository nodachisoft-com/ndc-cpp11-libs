#include <gtest/gtest.h>
#include "../../src/ndclibs.hpp"

#include <string>

// デバッグ用ディレクトリを設定
const std::string TESTTMP_DIR("./debug/");

// 存在しないファイルへのアクセス処理
TEST(FileAccessor, fa_case1)
{
  FileAccessor fa("./debug/fa_case1.txt");
  EXPECT_EQ(fa.getFilesize(), 0);
  EXPECT_EQ(fa.getFiletype(), FileType::FILE_NOT_FOUND);
}
