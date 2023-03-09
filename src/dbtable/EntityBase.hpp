#pragma once
#include <string>
#include <vector>
#include "../exception/index.hpp"

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

  public:
    EntityBase()
    {
    }

    virtual bool setData(std::vector<std::string> data)
    {
      throw TargetNotFoundException("No Impl Entity");
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
