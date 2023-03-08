#pragma once
#include <iostream>
#include <sstream>
#include <vector>

namespace nl
{
  class Dic
  {
  public:
    Dic();
  };
}

/*
TABLE に差し替え

Table<T> {
 vec<int>
 vec<float>
 vec<string>
 HashMap<int,int> pk;
 HashMap<string,int> nameToCol;		// 列名→列番号
 char colTypeList
 T getById()
 appendFromCSV

}
*/
