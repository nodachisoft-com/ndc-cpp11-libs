#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "../exception/index.hpp"

using namespace std::literals;

namespace nl
{
  struct ColumnDataMap
  {
    char type;
    int index;
  };

  class EntityBase
  {
  public:
    std::string _pk;

    std::unordered_map<std::string, std::string> dataMap;

  public:
    EntityBase()
    {
    }

    virtual bool setData(std::vector<std::string> data)
    {
      throw TargetNotFoundException("No Impl Entity");
    }

    bool setDataToColumnData(std::vector<std::string> columnNameList, std::vector<std::string> rowdata)
    {
      int size = columnNameList.size();
      for (int i = 0; i < size; i++)
      {
        std::string key = columnNameList[i];
        if (dataMap.count(key) != 0)
        {
          // 検査：キー重複を検知
          throw ArgumentValidatioinException(
              "Column Duplicate Detected! ColumnName=["s + key + "]"s);
        }
        dataMap[key] = rowdata[i];
      }
      return true;
    }

    bool isExistData(std::string columnName)
    {
      if (dataMap.count(columnName) != 0)
      {
        return true;
      }
      return false;
    }

    std::string getData(std::string columnName)
    {
      if (!isExistData(columnName))
      {
        return "";
      }
      return dataMap[columnName];
    }

    std::string getPK()
    {
      return _pk;
    }

    void setPK(std::string pk)
    {
      _pk = pk;
    }
  };
}
