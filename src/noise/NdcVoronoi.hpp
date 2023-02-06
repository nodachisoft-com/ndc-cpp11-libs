/**
 * @brief
 *  Voronoi Diagram を元に 2D の位置に応じた type を生成する
 *  機能を提供する
 */
#pragma once
#include "../random/index.hpp"
#include <iostream>

class NdcVoronoi
{
private:
  int randomSeed;
  int width;
  int height;
  struct Point
  {
    float x;
    float y;
    unsigned char type;
  };
  Point *point;

  /// @brief 高速用の inline floor 計算用
  /// @param x 計算対象の値
  /// @return floor 結果
  int fastfloor(float x)
  {
    return (((int)(x) < (x)) ? ((int)x) : ((int)x - 1));
  }

  /// @brief
  ///   inline での要素計算用メソッド。
  ///   Point の２次元配列相当の位置を計算する
  ///   要素の位置は (width, height) で mod 計算されループする
  /// @param x 位置X
  /// @param y 位置Y
  /// @return インデックスの番号
  int calcPosIndex(int x, int y)
  {
    return (x % width) + (y % height) * width;
  }

public:
  /// @brief Voronoi 図形の定義を設定し初期化する
  /// @param randomSeed 乱数を定義
  /// @param typeRange Voronoi の計算点がもつ種類 [0, typeRange] の範囲で乱数決定
  /// @param[in] px ループする X 方向の幅（Ex:256）
  /// @param[in] py ループする Y 方向の高さ（Ex:256）
  NdcVoronoi(const int randomSeed, const unsigned char typeRange, int px, int py);

  ~NdcVoronoi();

  /// @brief Voronoi Diagram Noise 2D
  /// @param[in] x 位置の指定。 [0.0-px) でループ
  /// @param[in] y 位置の指定。 [0.0-py) でループ
  /// @return 0 ～ typeRange ノイズ生成の結果
  unsigned char pos2(float x, float y);
};
