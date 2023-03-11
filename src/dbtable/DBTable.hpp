#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "../csv/CSVReader.hpp"
#include "EntityBase.hpp"
#include "../exception/NdcBaseException.hpp"
#include "../log/Logger.hpp"

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
      Logger logger;
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
        if (rowdata.size() == 0)
        {
          // データが存在しない
          logger.errorLog("DBTable::readCSV rowdata.size() is 0.");
          continue;
        }
        if (rowdata[0][0] == '#')
        {
          // コメント行で読込スキップする
          continue;
        }

        std::string pk = rowdata[0];

        if (isPkDataExist(pk))
        {
          logger.errorLog(std::string()
                              .append("PK Duplicate. PK=[")
                              .append(pk)
                              .append("]"));
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

    /// @brief Primary Key をもつデータがテーブル内に存在するかを判定する
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

    /// @brief Primary Key が完全一致するデータをテーブル内から取得する
    /// @param pk Primary Key
    /// @return Primary Key データが存在する場合、対象データを一見返す
    std::vector<XxxEntity> getByPK(std::string pk)
    {
      std::vector<XxxEntity> result;
      if (isPkDataExist(pk))
      {
        result.push_back(data.at(pk));
      }
      return result;
    }

    /// @brief テーブル名を返す
    /// @return テーブル名
    std::string getTablename()
    {
      return tablename;
    }

    /// @brief Primary Key が前方一致するデータをテーブル内から取得する
    /// @param pkStartWith Primary Key に対して前方一致検索する文字列
    /// @return 条件に一致する Entity のリスト
    std::vector<XxxEntity> selectStartWithByPK(std::string pkStartWith)
    {
      std::vector<XxxEntity> result;
      for (auto itr = data.begin(); itr != data.end(); ++itr)
      {
        std::string keyName(itr->first);

        if (keyName.size() >= pkStartWith.size() &&
            std::equal(std::begin(pkStartWith), std::end(pkStartWith), std::begin(keyName)))
        {
          result.push_back(data[keyName]);
        }
      }
      return result;
    }
  };
}
