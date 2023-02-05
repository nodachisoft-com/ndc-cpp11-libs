#include <gtest/gtest.h>
#include "../../src/ndclibs.hpp"

// 各種 append と read が正しく動作すること
TEST(MemoryBank, succ001)
{
  MemoryBank *buf = new MemoryBank(5);
  MemoryBank a(100);

  std::string name("Hogehoge!");
  std::string comp("ABCD");
  buf->append((char)10)                    // char
      ->append((short)123)                 // short
      ->append((int)456)                   // int
      ->append((long)1111)                 // long
      ->append((float)1.25f)               // float
      ->append((double)125.75)             // double
      ->append((bool)false)                // bool (false)
      ->append((bool)true)                 // bool (true)
      ->appendStringWithLength(name)       // std::string
      ->appendCharArrayWithLength("ABCD"); // char[]

  EXPECT_EQ((char)10, buf->readChar());
  EXPECT_EQ((short)123, buf->readShort());
  EXPECT_EQ((int)456, buf->readInt());
  EXPECT_EQ((long)1111, buf->readLong());
  EXPECT_EQ((float)1.25f, buf->readFloat());
  EXPECT_EQ((double)125.75, buf->readDouble());
  EXPECT_EQ((bool)false, buf->readBool());
  EXPECT_EQ((bool)true, buf->readBool());
  EXPECT_EQ(true, buf->readStringWithLength() == name);
  EXPECT_EQ(true, buf->readStringWithLength() == comp);
  delete buf;
}

// append した結果を汎用的な read で読み取れること
TEST(MemoryBank, succ002)
{
  MemoryBank *buf = new MemoryBank(5);

  // 書きこみ
  buf->append(5)->append(6)->append(7);

  // 読み込み
  int a, b, c = 0;
  buf->read(a);
  buf->read(b);
  buf->read(c);
  EXPECT_EQ(5, a);
  EXPECT_EQ(6, b);
  EXPECT_EQ(7, c);

  delete buf;
}

// append した結果、メモリ使用領域が拡大されていくこと
TEST(MemoryBank, succ003)
{
  MemoryBank *buf = new MemoryBank(5);

  // int INT_SIZE = sizeof(int);
  EXPECT_EQ(0, buf->getAllocMemorySize()); // まだメモリ利用なし
  EXPECT_EQ(0, buf->getUsingSize());       // まだメモリ利用なし

  // 1 バイト書きこみ
  buf->append('A');
  EXPECT_EQ(5, buf->getAllocMemorySize()); // 1スロットのメモリ領域確保
  EXPECT_EQ(1, buf->getUsingSize());       // 1バイト格納

  // 100 バイト書きこみ
  for (int i = 0; i < 100; i++)
  {
    buf->append((char)i);
  }
  EXPECT_EQ(105, buf->getAllocMemorySize()); // 21 スロットのメモリ領域確保
  EXPECT_EQ(101, buf->getUsingSize());       // 101 バイト格納

  delete buf;
}

// get / set でカーソル位置関係なくデータの読み込み、上書きができること
TEST(MemoryBank, succ004)
{
  MemoryBank *buf = new MemoryBank(5);
  buf->append('A')->append('B')->append('C')->append('D');
  // get できること。get はカーソル位置関係ないこと
  EXPECT_EQ('B', buf->get(1));
  EXPECT_EQ('A', buf->get(0));

  // set できること。
  buf->set(0, 'E');
  buf->set(1, 'F');

  // get でデータが更新されたことを確認
  EXPECT_EQ('E', buf->get(0));
  EXPECT_EQ('F', buf->get(1));

  // readChar でカーソル操作で読み込み確認
  EXPECT_EQ('E', buf->readChar());
  EXPECT_EQ('F', buf->readChar());
  EXPECT_EQ('C', buf->readChar());
  EXPECT_EQ('D', buf->readChar());

  delete buf;
}

// カーソル位置を初期化（先頭）に設定できること
TEST(MemoryBank, succ005)
{
  MemoryBank *buf = new MemoryBank(5);
  buf->append('A')->append('B');

  // readChar でカーソル操作で読み込み確認
  EXPECT_EQ('A', buf->readChar());
  EXPECT_EQ('B', buf->readChar());

  // カーソル位置を初期か
  buf->setCurPosToHead();

  // readChar でカーソル操作で読み込み確認
  EXPECT_EQ('A', buf->readChar());
  EXPECT_EQ('B', buf->readChar());

  delete buf;
}
