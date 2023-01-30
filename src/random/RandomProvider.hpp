/**
 * @file RandomProvider.hpp
 * @brief
 *  乱数機能を API として提供するインターフェイスをプロバイダ機能を手依拠する。
 *  API 利用にあたっては具体的なアルゴリズムは隠蔽化され、利用者は意識する必要が無い。
 */
#pragma once
#include "../ndclibs.hpp"

/// @brief 乱数生成のアルゴリズム種類を定義
enum class RND_TYPE : int
{
    /// 線形合同乱数
    LINEAR,

    /// メルセンヌ・ツイスタ ( 2^19937 - 1 周期)
    MT19937,
};

/**
 * @brief 疑似乱数生成機能をもつ API をインターフェイスとして取得する機能を提供する
 */
class RandomProvider
{
public:
    /// @brief 疑似乱数生成機能をもつ API をインターフェイスとして取得
    /// @param type 使用する乱数アルゴリズム
    /// @param seed 疑似乱数の種を指定
    /// @return 疑似乱数生成機能をもつ API（インターフェイス）
    static IRandomizer *getRandomizer(RND_TYPE type, uint seed);
};
