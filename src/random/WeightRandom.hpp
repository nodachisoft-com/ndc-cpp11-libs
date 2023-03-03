
/**
 * @file WeightRandom.hpp
 * @brief 重み付きの要素をもったリストから重みの比率（確率）で要素を取り出す機能を提供する
 */
#pragma once
#include <vector>
#include "MtRandomizer.hpp"
#include "../exception/index.hpp"

namespace nl
{

  /**
   * @brief
   *  重み付きの要素をもったリストから重みの比率（確率）で要素を取り出す機能を持つクラス
   */
  template <class T>
  class WeightRandom
  {
  private:
    MtRandomizer rand;

    struct Elem
    {
      float perc;
      T contents;
    };

  private:
    std::vector<Elem> list;

  public:
    WeightRandom() : list({})
    {
      rand = MtRandomizer(0);
    }

    void init(long randomSeed)
    {
      rand = MtRandomizer(randomSeed);
    }

    void push(const float perc, T contents)
    {
      list.push_back(Elem{perc, contents});
    }

    int length()
    {
      return list.size();
    }

    float sumRandomPerc()
    {
      float sum = 0.0f;
      int len = length();
      for (int i = 0; i < len; i++)
      {
        Elem e = list.at(i);
        sum += e.perc;
      }
      return sum;
    }

    T getRandElem()
    {
      int len = length();
      float rndTarget = rand.getRndFloat(0.0f, sumRandomPerc());
      float countRndSum = 0.0f;
      for (int i = 0; i < len; i++)
      {
        Elem e = list.at(i);
        if (countRndSum <= rndTarget && rndTarget < countRndSum + e.perc)
        {
          // 取得するランダムカウントの範囲に収まっている
          return e.contents;
        }
        countRndSum += rndTarget;
      }
      throw TargetNotFoundException("WeightRandom#getRandElem Not Found Element.");
    }
  };
}
