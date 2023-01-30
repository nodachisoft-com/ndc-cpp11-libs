/**
 * @file IRandomizer.hpp
 * @brief
 *  乱数生成器から乱数を取り出すための Interface を提供する。
 *  実際の乱数生成の実装と分離可能。
 */
#pragma once

/// @brief 乱数生成器から乱数を取り出すための Interface
class IRandomizer
{
public:
  /// @brief デストラクタ
  virtual ~IRandomizer(){};

  /// @brief 範囲 [from,to) で乱数を生成する
  /// @param[in] from 生成する乱数幅の下限を指定
  /// @param[in] to 生成する乱数幅の上限を指定
  /// @return float 型の乱数生成結果
  virtual float getRndFloat(float from, float to) = 0;

  /// @brief 範囲 [from,to] で乱数を生成する
  /// @param[in] from 生成する乱数幅の下限を指定
  /// @param[in] to 生成する乱数幅の上限を指定
  /// @return int 型の乱数生成結果
  virtual int getRndInt(int from, int to) = 0;

  // TODO: 追加開発対象
  // virtual int getRndIntRange( From-To-Array[]) : int
  // getRndFloatRange(From - To - Aarray[]) : float
};
