#include "CSVReader.hpp"

using namespace nl;

void CSVReader::readCsv(const std::string &csv_data)
{
  std::vector<std::vector<std::string>> result;
  std::istringstream stream(csv_data);
  std::string line;
  while (std::getline(stream, line))
  {
    std::vector<std::string> row;
    size_t start = 0, end = 0;
    bool escape = false;
    while (end < line.size())
    {
      if (line[end] == escape_char_)
      {
        escape = true;
      }
      else if (line[end] == delimiter_ && !escape)
      {
        row.push_back(line.substr(start, end - start));
        start = end + 1;
      }
      else
      {
        escape = false;
      }
      end++;
    }
    row.push_back(line.substr(start));
    result.push_back(row);
  }
  data = result;
}

std::string CSVReader::getCell(int col, int row)
{
  int rowSize = data.size();
  if (row < 0 || rowSize < row)
  {
    std::string msg;
    msg += "CSVReader::getCell(" + std::to_string(row) + "," + std::to_string(col) + ") is out of range.";
    throw OutOfRangeAccessException(msg);
  }
  int colSize = data[row].size();
  if (col < 0 || colSize < col)
  {
    std::string msg;
    msg += "CSVReader::getCell(" + std::to_string(row) + "," + std::to_string(col) + ") is out of range.";
    throw OutOfRangeAccessException(msg);
  }
  return data[row][col];
}
