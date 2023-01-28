#pragma once
#include <iostream>
#include "Randomizer.hpp"

enum class RND_TYPE : int
{
    // 線形合同乱数
    LINEAR,
    // メルセンヌ・ツイスタ ( 2^19937 - 1 周期)
    MT19937,
};

/**
 * 議事乱数生成器 を取得する機能を提供する
 */
class RandomProvider
{
public:
    static Randomizer *getRandomizer(RND_TYPE type, uint seed);
};
