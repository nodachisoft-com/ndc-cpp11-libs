#include <vector>
#include <string>
#include <sstream>
#include "ScalableByteArray.hpp"
#include "../exception/index.hpp"

/**
 * @fn
 * コンストラクタ
 * @brief スケーラブルなバイト列操作用のクラスを初期化する
 * @param (引数名) 引数の説明
 * @param (引数名) 引数の説明
 * @return 戻り値の説明
 */
ScalableByteArray::ScalableByteArray()
{
  memoryBlockSize = DEFAULT_MEMORY_BLOCK_SIZE;
}

ScalableByteArray::ScalableByteArray(int _memoryBlockSize)
{
  memoryBlockSize = _memoryBlockSize;
}

// デストラクタ。必要なだけ動的に確保したメモリブロックのスロットを解放する
ScalableByteArray::~ScalableByteArray()
{
  // 使用しているメモリスロットの参照先メモリを解放する
  int memorySize = memory.size();
  for (int slotNo = 0; slotNo < memorySize; slotNo++)
  {
    free(memory[slotNo]);
  }
}

// バイト列の指定の要素にアクセスし、１バイトを返す
// @pram index アクセスするメモリの要素番号
char ScalableByteArray::get(int index)
{
  if (index > endPos)
  {
    // メモリ範囲外へのアクセスが発生した
    // アクセス可能な要素の最大を計算
    const int accessableRangeLimit = memoryBlockSize * memory.size() - 1;
    std::stringstream msg;
    msg << "Access Violation offset=[" << index << "], Accessable Range=["
        << 0 << "," << accessableRangeLimit << "]" << std::flush;
    throw OutOfRangeAccessException(std::string(msg.str()));
  }
  int slotNo = index / memoryBlockSize;
  int offset = index % memoryBlockSize;
  char result = memory[slotNo][offset];
  return result;
}

void ScalableByteArray::set(int index, char value)
{
  if (index > endPos)
  {
    // メモリ範囲外へのアクセスが発生した
    // アクセス可能な要素の最大を計算
    const int accessableRangeLimit = memoryBlockSize * memory.size() - 1;
    std::stringstream msg;
    msg << "Access Violation offset=[" << index << "], Accessable Range=["
        << 0 << "," << accessableRangeLimit << "]" << std::flush;
    throw OutOfRangeAccessException(std::string(msg.str()));
  }
  int slotNo = index / memoryBlockSize;
  int offset = index % memoryBlockSize;
  memory[slotNo][offset] = value;
}

ScalableByteArray *ScalableByteArray::appendByte(char value)
{
  int nextEndPos = endPos + 1;
  bool isBound = (nextEndPos % memoryBlockSize == 0 ? true : false);
  if (isBound)
  {
    // メモリブロックの末まで使用している状態のため、
    // 次のスロットにメモリを確保して使用可能にする
    if (useNewMemorySlot() == false)
    {
      throw OutOfMemoryException("OUT OF MEMORY!!");
    }
  }
  endPos++;
  set(endPos, value);
  return this;
}


template <typename X>
ScalableByteArray *ScalableByteArray::append(X value)
{
  char *byteArray = (char *)(void *)&value;
  for (int i = 0; i < sizeof(X); i++)
  {
    appendByte(byteArray[i]);
  }
  return this;
}
template ScalableByteArray *ScalableByteArray::append<char>(char);
template ScalableByteArray *ScalableByteArray::append<short>(short);
template ScalableByteArray *ScalableByteArray::append<int>(int);
template ScalableByteArray *ScalableByteArray::append<long>(long);
template ScalableByteArray *ScalableByteArray::append<float>(float);
template ScalableByteArray *ScalableByteArray::append<double>(double);

// 読み取りカーソル位置をバッファの頭にセット
void ScalableByteArray::setCurPosToHead()
{
  curPos = 0;
}

// 現在のカーソル位置から char を読み込み、カーソル位置を進める
char ScalableByteArray::readChar()
{
  char result = get(curPos);
  curPos++;
  return result;
}

// 現在のカーソル位置から int を読み込み、カーソル位置を進める
int ScalableByteArray::readInt()
{
  int result = 0;
  char *mem = (char *)(void *)(&result);

  for (int i = 0; i < sizeof(int); i++)
  {
    mem[i] = readChar();
  }
  return result;
}

// バイト列保存領域として確保しているメモリ使用量を取得する
// @return バッファのメモリ使用量
int ScalableByteArray::getAllocMemorySize()
{
  int usingMemorySlot = memory.size();
  long memorySize = usingMemorySlot * memoryBlockSize;
  return memorySize;
}

// アクセス可能な割り当て済みバイト列のバイト数の長さ取得する。
// 3 Byte を保存済みなら 3 を返す
// 確保したメモリ容量ブロックはスロット単位であり、 getAllocMemorySize() とは
// 異なる結果となる
// @return バイト列の長さ。
int ScalableByteArray::getUsingSize()
{
  return endPos + 1;
}

// 使用しているメモリスロット数、メモリ容量などのデバッグ情報を出力します
void ScalableByteArray::debug()
{
  int usingMemorySlot = memory.size();
  long memorySize = usingMemorySlot * memoryBlockSize;
  std::cout
      << "[INFO] Using Memory Slot Count : " << usingMemorySlot << std::endl;
  std::cout << "[INFO] Using Memory Mount Size : " << memorySize << std::endl;
}

// ========= PRIVATE METHOD ===========
// 追加でメモリスロットにメモリを割り当て、領域をすべて 0 で初期化する
// @return 処理成功なら TRUE、メモリ確保に失敗した場合 FALSE を返す
bool ScalableByteArray::useNewMemorySlot()
{
  // char *newBlock = (char *)malloc(sizeof(char) * memoryBlockSize);
  char *newBlock = (char *)calloc(memoryBlockSize, sizeof(int));
  if (newBlock == NULL)
  {
    return false;
  }
  memory.push_back(newBlock);
  return true;
}
