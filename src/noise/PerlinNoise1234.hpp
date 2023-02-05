/**
 * @brief
 *  Perlin Noise、Perlin Perodic Noise について 1D,2D,3D,4D に対応した
 *  機能を提供する
 */
#pragma once

class PerlinNoise1234
{
private:
  static float FADE(float t);
  static int FASTFLOOR(float x);
  static float LERP(float t, float a, float b);

  static unsigned char perm[];

  static float grad1(int hash, float x);
  static float grad2(int hash, float x, float y);

  static float grad3(int hash, float x, float y, float z);

  static float grad4(int hash, float x, float y, float z, float t);

public:
  static float noise1(float x);
  static float noise2(float x, float y);
  static float noise3(float x, float y, float z);
  static float noise4(float x, float y, float z, float w);

  /// @brief Perlin Perodic Noise 1D
  /// @param[in] x 位置の指定 [0.0-1.0)
  /// @param[in] px ノイズ発生の基準点の数（Ex:256）
  /// @return -1.0～1.0 ノイズ生成の結果
  static float pnoise1(float x, int px);

  /// @brief Perlin Perodic Noise 2D
  /// @param[in] x 位置の指定 [0.0-1.0)
  /// @param[in] y 位置の指定 [0.0-1.0)
  /// @param px ノイズ発生の基準点の X 方向の数（Ex:256）
  /// @param py ノイズ発生の基準点の Y 方向の数（Ex:256）
  /// @return -1.0～1.0 ノイズ生成の結果
  static float pnoise2(float x, float y, int px, int py);
  static float pnoise3(float x, float y, float z, int px, int py, int pz);
  static float pnoise4(float x, float y, float z, float w, int px, int py, int pz, int pw);
};
