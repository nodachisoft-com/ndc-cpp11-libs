#include <gtest/gtest.h>
#include "../../src/ndclibs.hpp"

#include <string>

// デバッグ用ディレクトリを設定
const std::string TESTTMP_DIR("./debug/");

// 存在しないファイルへのアクセス処理
TEST(FileAccessor, fa_constructor_case1)
{
  std::string path("./debug/fa_case1_not_exists.txt");
  FileAccessor fa(path);
  EXPECT_EQ(fa.calcMemoryCrc32(), 0);
  EXPECT_EQ(fa.readFileSync(), false);
  EXPECT_EQ(fa.getFilesize(), 0);
  EXPECT_EQ(fa.getFiletype(), FileType::FILE_NOT_FOUND);
  EXPECT_EQ(fa.getMemoryBank()->getUsingSize(), 0);
  EXPECT_EQ(fa.getFilePath(), path);
  EXPECT_EQ(fa.isOpenFile(), false);
  EXPECT_EQ(fa.getProgress(), 0.0f);
  EXPECT_EQ(fa.getFileStatus(), FileStatus::NOT_LOADING);
}

// 存在しないファイルへのアクセス処理でファイルを作成
TEST(FileAccessor, fa_case2_writeFileSync)
{
  std::string path("./debug/fa_case2_newfile.txt");
  FileAccessor fa(path);
  EXPECT_EQ(fa.getFiletype(), FileType::FILE_NOT_FOUND);
  EXPECT_EQ(fa.getMemoryBank()->getUsingSize(), 0);
  EXPECT_EQ(fa.getFileStatus(), FileStatus::NOT_LOADING);

  // メモリバッファに文字列追加
  std::string msg("This is Test Message!");
  for (int i = 0; i < msg.size(); i++)
  {
    fa.getMemoryBank()->appendByte(msg[i]);
  }
  EXPECT_EQ(fa.writeFileSync(), true); // 書き込み

  // 書き込みが成功した場合、ファイルへのアクセスが可能である
  EXPECT_EQ(fa.getFiletype(), FileType::FILE);
  EXPECT_EQ(fa.getFileStatus(), FileStatus::AVAILABLE);
}

// 1.存在しないファイルへのアクセス処理でファイルを作成
// 2.作成したファイルを読み込み、データ取り出し
TEST(FileAccessor, fa_case2_writeFileSync_and_read)
{
  std::string path("./debug/fa_case2_writeFileSync_and_read.txt");
  FileAccessor fa(path);
  EXPECT_EQ(fa.getFiletype(), FileType::FILE_NOT_FOUND);

  // メモリバッファに文字列追加
  std::string msg1("1st Message!");
  std::string msg2("2nd Next Message!");
  fa.getMemoryBank()->appendStringWithLength(msg1);
  fa.getMemoryBank()->appendStringWithLength(msg2);
  EXPECT_EQ(fa.writeFileSync(), true); // 書き込み

  // 別途新しくファイルを開く
  FileAccessor fa2(path);
  EXPECT_EQ(fa2.getFiletype(), FileType::FILE);
  EXPECT_EQ(fa2.readFileSync(), true);                                         // ファイル内容の読み込み
  EXPECT_EQ(fa2.getMemoryBank()->readStringWithLength(), "1st Message!");      // 取り出し
  EXPECT_EQ(fa2.getMemoryBank()->readStringWithLength(), "2nd Next Message!"); // 取り出し
}

// 追記モードでファイルに文字列を書き込み
TEST(FileAccessor, fa_case3_appendStringToFileSync)
{
  std::string path("./debug/fa_case3_appendStringToFileSync.txt");
  FileAccessor::appendStringToFileSync(path, "abcd");
  FileAccessor fa(path);
  EXPECT_EQ(fa.readFileSync(), true);
  // EXPECT_EQ(3984772369, fa.calcMemoryCrc32());
  EXPECT_EQ(0xed82cd11, fa.calcMemoryCrc32());
  // ed82cd11
}
