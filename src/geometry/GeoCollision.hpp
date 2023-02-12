#pragma once

class GeoCollision
{
public:
  /// @brief 点p(x,y) と、線分 ( 点t1(x,y) - 点t2(x,y) ) の最短距離の２乗を返す
  /// @param px 点p の x 成分
  /// @param py 点p の y 成分
  /// @param t1x 線分を構成する点t1 の x 成分
  /// @param t1y 線分を構成する点t1 の y 成分
  /// @param t2x 線分を構成する点t2 の x 成分
  /// @param t2y 線分を構成する点t2 の y 成分
  /// @return 点p(x,y) と、線分 ( 点t1(x,y) - 点t2(x,y) ) の最短距離の２乗
  static float powOfDistance_Point_To_LineSegment(const float px, const float py,
                                                  const float t1x, const float t1y,
                                                  const float t2x, const float t2y);

  /// @brief 点p(x,y) と、線分 ( 点t1(x,y) - 点t2(x,y) ) の最短距離が、指定した距離内かを判定する
  /// @param px 点p の x 成分
  /// @param py 点p の y 成分
  /// @param t1x 線分を構成する点t1 の x 成分
  /// @param t1y 線分を構成する点t1 の y 成分
  /// @param t2x 線分を構成する点t2 の x 成分
  /// @param t2y 線分を構成する点t2 の y 成分
  /// @return 指定した距離の内部なら true を返す
  static bool isInsideOfDistance_Point_To_LineSegment(const float px, const float py,
                                                      const float t1x, const float t1y,
                                                      const float t2x, const float t2y, const float condDistance);

  /// @brief 点p(x,y) と 円 ( 中心点c(x,y)、半径 r ) までの距離の２乗を計算する
  /// @param px 点p の x 成分
  /// @param py 点p の y 成分
  /// @param cx 円の中心点 c の x 成分
  /// @param cy 円の中心点 c の y 成分
  /// @param r 円の半径
  /// @return 点p(x,y) と 円 ( 中心点c(x,y)、半径 r ) までの距離の２乗を返す
  static float powOfDistance_Point_To_Circle(const float px, const float py,
                                             const float cx, const float cy,
                                             const float r);

  /// @brief 点p(x,y) に、円 ( 中心点c(x,y)、半径 r ) が含まれているかを判定する
  /// @param px 点p の x 成分
  /// @param py 点p の y 成分
  /// @param cx 円の中心点 c の x 成分
  /// @param cy 円の中心点 c の y 成分
  /// @param r 円の半径
  /// @return 点が円に含まれているなら true。境界値も含む。
  static bool isInsideOfDistance_Point_To_Circle(const float px, const float py,
                                                 const float cx, const float cy,
                                                 const float r);
};
