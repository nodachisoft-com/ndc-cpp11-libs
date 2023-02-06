/**
 * @brief
 *  Perlin Noise、Perlin Perodic Noise について 1D,2D,3D,4D に対応した
 *  機能を提供する
 */
#pragma once
#include "../random/index.hpp"
#include <iostream>

class PerlinNoise1234
{
private:
  float fade(float t)
  {
    return (t * t * t * (t * (t * 6 - 15) + 10));
  }
  int fastfloor(float x)
  {
    return (((int)(x) < (x)) ? ((int)x) : ((int)x - 1));
  }
  float lerp(float t, float a, float b)
  {
    return ((a) + (t) * ((b) - (a)));
  }

  unsigned char perm[512] = {151, 160, 137, 91, 90, 15,
                             131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23,
                             190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33,
                             88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166,
                             77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40, 244,
                             102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169, 200, 196,
                             135, 130, 116, 188, 159, 86, 164, 100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123,
                             5, 202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42,
                             223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167, 43, 172, 9,
                             129, 22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228,
                             251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107,
                             49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254,
                             138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180,
                             // LOOP
                             151,
                             160, 137, 91, 90, 15,
                             131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23,
                             190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33,
                             88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166,
                             77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40, 244,
                             102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169, 200, 196,
                             135, 130, 116, 188, 159, 86, 164, 100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123,
                             5, 202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42,
                             223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167, 43, 172, 9,
                             129, 22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228,
                             251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107,
                             49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254,
                             138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180};

  float grad1(int hash, float x);
  float grad2(int hash, float x, float y);

  float grad3(int hash, float x, float y, float z);

  float grad4(int hash, float x, float y, float z, float t);

public:
  PerlinNoise1234(int randomSeed);

  float noise1(float x);
  float noise2(float x, float y);
  float noise3(float x, float y, float z);
  float noise4(float x, float y, float z, float w);

  /// @brief Perlin Perodic Noise 1D
  /// @param[in] x 位置の指定 [0.0-1.0)
  /// @param[in] px ノイズ発生の基準点の数（Ex:256）
  /// @return -1.0～1.0 ノイズ生成の結果
  float pnoise1(float x, int px);

  /// @brief Perlin Perodic Noise 2D
  /// @param[in] x 位置の指定 [0.0-1.0)
  /// @param[in] y 位置の指定 [0.0-1.0)
  /// @param[in] px ループする X 方向の幅（Ex:256）
  /// @param[in] py ループする Y 方向の高さ（Ex:256）
  /// @param[in] genHeight 生成するノイズの高さ(0.0f ～ )
  /// @return 0.0f ～ genHeight ノイズ生成の結果
  float pnoise2(float x, float y, int px, int py, float genHeight);
  float pnoise3(float x, float y, float z, int px, int py, int pz);
  float pnoise4(float x, float y, float z, float w, int px, int py, int pz, int pw);
};
