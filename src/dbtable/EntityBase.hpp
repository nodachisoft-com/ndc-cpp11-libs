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

    /// @brief
    /// @param columnNameList カラム名称一覧
    /// @param columnTypeList カラム型の一覧
    /// @param rowdata データ本体
    /// @return 正常にデータ設定できたら true
    bool setDataToColumnData(std::vector<std::string> columnNameList,
                             std::vector<std::string> columnTypeList,
                             std::vector<std::string> rowdata)
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
        validateDataConvertibleFromString(columnTypeList[i], rowdata[i]);
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

  private:
    bool validateDataConvertibleFromString(std::string type, std::string data)
    {
      if (type.size() == 0)
      {
        return false;
      }
      char typeChar = type.c_str()[0];
      if (typeChar == 'S')
      {
        // STRING 型
        return true;
      }
      else if (typeChar == 'I')
      {
        // INT 型
        try
        {
          std::stoi(data);
        }
        catch (std::invalid_argument &)
        {
          Logger logger;
          logger.errorLog("DBTable Not INTEGER data. data=["s + data + "]"s);
          return false;
        }
      }
      else if (typeChar == 'F')
      {
        // INT 型
        try
        {
          std::stof(data);
        }
        catch (std::invalid_argument &)
        {
          Logger logger;
          logger.errorLog("DBTable Not FLOAT data. data=["s + data + "]"s);
          return false;
        }
      }
      else if (typeChar == 'B')
      {
        // BOOL 型
        if (data != "TRUE" && data != "FALSE")
        {
          Logger logger;
          logger.errorLog("DBTable Not BOOL data. data=["s + data + "]"s);
          return false;
        }
      }
      else
      {
        Logger logger;
        logger.errorLog("Unknown Data type. type=["s + type + "]"s);
        return false;
      }
      return true;
    }
  };
}
