#include "NdcVoronoi.hpp"

NdcVoronoi::NdcVoronoi(const int _randomSeed, const unsigned char typeRange, int px, int py)
{
  randomSeed = _randomSeed;
  MtRandomizer rand(_randomSeed);
  width = px;
  height = py;

  // Voronoi の計算用の格子点の位置を作成
  point = new Point[px * py];
  for (int v = 0; v < py; v++)
  {
    for (int u = 0; u < px; u++)
    {
      // 隣接する点を超えない範囲で乱数で位置に変化を加える
      int index = calcPosIndex(u, v); // v * px + u;
      point[index].x = rand.getRndFloat(-0.48f, 0.48f);
      point[index].y = rand.getRndFloat(-0.48f, 0.48f);
      point[index].type = rand.getRndInt(0, typeRange);
    }
  }
}

NdcVoronoi::~NdcVoronoi()
{
  delete[] point;
}

unsigned char NdcVoronoi::pos2(float x, float y)
{
  // 最寄りの 4 点
  Point UL, UR, BL, BR;
  bool isRightLoop = false;
  bool isBottomLoop = false;

  int floorX = fastfloor(x);
  int floorY = fastfloor(y);

  if (floorX + 1 > width)
  {
    // 右側がループして、左端の点を判断に使用する必要あり
    isRightLoop = true;
  }
  if (floorY + 1 > height)
  {
    // 下側がループして、上端の点を判断に使用する必要あり
    isBottomLoop = true;
  }

  int rightPosX = (floorX + 1) % width;
  int bottomPosY = (floorY + 1) % height;

  // TODO calcPosIndex で置き換え
  UL = point[floorX + floorY * width];
  UR = point[rightPosX + floorY * width];
  BL = point[floorX + bottomPosY * width];
  BR = point[rightPosX + bottomPosY * width];

  return 1;
}
