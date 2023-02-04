#include "../../src/ndclibs.hpp"
// #include "../../src/image/index.hpp"

int main()
{
  std::string path = FileAccessMgr::getCurDir();
  std::cout << "PATH=" << path << std::endl;
}
