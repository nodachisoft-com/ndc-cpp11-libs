#include "../../src/ndclibs.hpp"
#include <string>
#include <vector>

using namespace nl;

int main()
{
  std::string path = "./debug/fa_crc32_largefile_case001.bin";
  FileAccessor faWrite(path);

  MemoryBank mem;
  // for (int i = 0; i < 1024 * 16; i++)
  for (int i = 0; i < 15; i++)
  {
    unsigned char val = i % 14;
    mem.appendByte(val);
  }

  faWrite.setMemoryBank(&mem);
  std::cout << "memory size(write):" << mem.getUsingSize() << std::endl;

  faWrite.writeFileSync();

  // 改めてファイルを読み込み
  FileAccessor faRead(path);
  faRead.readFileSync();

  std::cout << "memory size(read):" << faRead.getMemoryBank()->getUsingSize() << std::endl;
  // debug
  for (int i = 0; i < faRead.getMemoryBank()->getUsingSize(); i++)
  {
    std::cout << "[" << i << " = " << (int)(faRead.getMemoryBank()->get(i)) << "] ";
  }
  std::cout << std::endl;
}
