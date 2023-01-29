#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../exception/index.hpp"

class ScalableByteArray
{
  // デフォルトでの 1 つのメモリブロックは 1 MB
  const int DEFAULT_MEMORY_BLOCK_SIZE = 1024 * 1024;

  // メモリブロックのサイズ。初期化時にのみ設定可能
  // 1K ～ 8M 程度を推奨。この単位でメモリを calloc して連番でアクセス可能とする
  // 仮想メモリのように動作する。
  // メモリが小さく断片的すぎると、オーバーヘッドが発生する可能性がある
  int memoryBlockSize;

  // アクセス可能なメモリサイズの上限（要素）
  // この要素まで get() などでアクセス可能。
  int endPos = -1;

  // 読み取りカーソル位置
  int curPos = 0;

  // 保持するメモリへの参照の配列
  std::vector<char *> memory;

public:
  ScalableByteArray();
  ScalableByteArray(int memoryBlockSize);
  ~ScalableByteArray();
  char get(int index);
  void set(int index, char value);

  ScalableByteArray *appendByte(char value);
  template <typename X>
  ScalableByteArray *append(X value);

  char readChar();
  short readShort();
  int readInt();
  long readLong();
  float readFloat();
  double readDouble();
  std::string readString();

  // 読み取りカーソル位置をバッファの頭にセット
  void setCurPosToHead();

  // バイト列保存領域として確保しているメモリ使用量を取得する
  // @return バッファのメモリ使用量
  int getAllocMemorySize();

  // アクセス可能な割り当て済みバイト列のバイト数の長さ取得する。
  // 3 Byte を保存済みなら 3 を返す
  // 確保したメモリ容量ブロックはスロット単位であり、 getAllocMemorySize() とは
  // 異なる結果となる
  // @return バイト列の長さ。
  int getUsingSize();

  // 使用しているメモリスロット数、メモリ容量などのデバッグ情報を出力します
  void debug();

private:
  // 追加でメモリスロットにメモリを割り当て、領域をすべて 0 で初期化する
  // @return 処理成功なら TRUE、メモリ確保に失敗した場合 FALSE を返す
  bool useNewMemorySlot();
};
