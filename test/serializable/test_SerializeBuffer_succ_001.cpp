#include <gtest/gtest.h>
#include "../../src/serializable/index.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <cstddef>
#include <cstring>

#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>
// #include "../../lib/prod/cereal-1.3.2/include/cereal/cereal.hpp"
// #include "../../lib/prod/cereal-1.3.2/include/cereal/archives/json.hpp"

/*
class TestData : public ISerializable
{
  TestData();
  ostream serialize(ostream data)
  {
  }
  void deserialize(ostream data)
  {
  }
};
*/

TEST(SerializeBuffer, testcase1)
{
  std::ostringstream oss;
  // oss << "otringstream sample: " << 123;

  std::string n("Amaji");
  int l = n.length();
  int INT_SIZE = sizeof(int);
  std::cout
      << "int size=" << INT_SIZE << std::endl;

  // DEBUG
  void *p = (void *)&l;
  char *t = (char *)p;
  for (int i = 0; i < INT_SIZE; i++)
  {
    printf("%d,", t[i]);
  }

  // int -> char * に変換
  /*
  void *p = (void *)&l;
  char *t = (char *)p;
  char sel[INT_SIZE];
  for ( int i = 0 ; i < INT_SIZE ; i++ ) {
    sel[i] = t[i];
  }*/
  /*
  char bytes[INT_SIZE];
  std::memcpy(bytes, &l, INT_SIZE);

  oss.write(bytes, INT_SIZE);

  oss.seekp(oss.beg);

  std::cout << oss << std::endl;
  */

  /*
  streambuf *aa = oss.rdbuf();
  for (int i = 0; i < INT_SIZE; i++)
  {
    printf("%d,", aa->sgetc());
  }
  */

  // sel[0] = (char)p;

  // void *p = &l;
  // char c[4];
  // c[0] = (char)p;

  // char *tmp_l = (char *)l;
  // oss.write((char *)tmp_l, sizeof(int));
  //  oss.write(n.c_str(), l);

  // std::string str(oss.str());

  // std::cout << str << std::endl;
  EXPECT_EQ(3, 3);
}
