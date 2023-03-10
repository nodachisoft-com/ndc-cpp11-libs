#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "../csv/CSVReader.hpp"
#include "EntityBase.hpp"
#include "../exception/index.hpp"

namespace nl
{
  template <class XxxEntity>
  class DBTable
  {
  private:
    /// @brief テーブル名称を定義
    std::string tablename;

    /// @brief 辞書データを格納する
    std::unordered_map<std::string, XxxEntity> data;

  public:
    /// @brief 初期化
    DBTable()
    {
      data = std::unordered_map<std::string, XxxEntity>{};
    }

    /// @brief CSV データを辞書データとして読み込む
    /// @param csv 読み込むデータ元
    /// @return 読み込んだデータ行。重複などのエラー検知データは対象外。
    int readCSV(CSVReader &csv)
    {
      int rowsize = csv.rowsize();
      if (rowsize <= 1)
      {
        throw ArgumentValidatioinException("csv data is too short.");
      }
      // テーブル名取得
      tablename = csv.getRowCellList(0).at(0);

      int insertCount = 0;
      for (int i = 1; i < rowsize; i++)
      {
        std::vector<std::string> rowdata = csv.getRowCellList(i);
        std::string pk = rowdata[0];
        if (isPkDataExist(pk))
        {
          std::cout << "PK Duplicate. PK=[" << pk << "]" << std::endl;
          continue;
        }
        XxxEntity entity;
        entity.setPK(pk);
        entity.setData(rowdata);
        insertCount++;
        data[pk] = entity;
      }
      return insertCount;
    }

    /// @brief Primary Key をもつデータが辞書内に存在するかを判定する
    /// @param pk Primary Key
    /// @return Primary Key データが存在する場合 true を返す
    bool isPkDataExist(std::string pk)
    {
      return data.count(pk) != 0 ? true : false;
    }

    int size()
    {
      return data.size();
    }

    std::vector<XxxEntity> getByPK(std::string pk)
    {
      std::vector<XxxEntity> result;
      if (isPkDataExist(pk))
      {
        result.push_back(data.at(pk));
      }
      return result;
    }
    std::string getTablename()
    {
      return tablename;
    }
  };
}