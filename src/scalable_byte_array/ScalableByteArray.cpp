#include <vector>
#include <string>
#include <sstream>
#include "ScalableByteArray.hpp"
#include "../exception/index.hpp"

/**
 * コンストラクタ
 * @brief スケーラブルなバイト列操作用のクラスを初期化する
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

char ScalableByteArray::get(int index)
{
  if (index < 0 || index > endPos)
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
  if (index < 0 || index > endPos)
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

ScalableByteArray *ScalableByteArray::appendString(std::string &value)
{
  int len = value.length();
  append(len);

  const char *buf = value.c_str();
  // 文字列本体を記録
  for (int i = 0; i < len; i++)
  {
    appendByte(buf[i]);
  }
  return this;
}

template <typename X>
void ScalableByteArray::read(X &value)
{
  // short result = 0;
  char *mem = (char *)(void *)(&value);

  for (int i = 0; i < sizeof(X); i++)
  {
    mem[i] = readChar();
  }
  // return result;
}
template void ScalableByteArray::read<char>(char &v);
template void ScalableByteArray::read<int>(int &v);
template void ScalableByteArray::read<float>(float &v);

// テンプレート関数で対応不可の個別処理
/*
ScalableByteArray *ScalableByteArray::appendCharArray(char *value, int length)
{
  append(length); // 文字列の長さを記録

  // 文字列本体を記録
  char *byteArray = (char *)(void *)&value;
  for (int i = 0; i < length; i++)
  {
    appendByte(byteArray[i]);
  }
  return this;
}
*/

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

// 現在のカーソル位置から short を読み込み、カーソル位置を進める
short ScalableByteArray::readShort()
{
  short result = 0;
  char *mem = (char *)(void *)(&result);

  for (int i = 0; i < sizeof(short); i++)
  {
    mem[i] = readChar();
  }
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

// 現在のカーソル位置から long を読み込み、カーソル位置を進める
long ScalableByteArray::readLong()
{
  long result = 0;
  char *mem = (char *)(void *)(&result);

  for (int i = 0; i < sizeof(long); i++)
  {
    mem[i] = readChar();
  }
  return result;
}

// 現在のカーソル位置から float を読み込み、カーソル位置を進める
float ScalableByteArray::readFloat()
{
  float result = 0;
  char *mem = (char *)(void *)(&result);

  for (int i = 0; i < sizeof(float); i++)
  {
    mem[i] = readChar();
  }
  return result;
}

// 現在のカーソル位置から double を読み込み、カーソル位置を進める
double ScalableByteArray::readDouble()
{
  double result = 0;
  char *mem = (char *)(void *)(&result);

  for (int i = 0; i < sizeof(double); i++)
  {
    mem[i] = readChar();
  }
  return result;
}

// 現在のカーソル位置から char* を記録された長さぶん読み込み、
// 末尾に終端文字（\0）を付与して返す。読み取ったぶんのカーソル位置を進める
std::string ScalableByteArray::readString(std::string &value)
{
  int length = readInt();
  char newCharArray[length + 1];
  char *mem = (char *)(void *)(&newCharArray);
  for (int i = 0; i < length; i++)
  {
    mem[i] = readChar();
  }
  mem[length] = '\0'; // 終端文字を追加
  std::string result(newCharArray);
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
