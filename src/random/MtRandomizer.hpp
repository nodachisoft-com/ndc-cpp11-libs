#pragma once
#include <random>
#include "IRandomizer.hpp"

class MtRandomizer : public IRandomizer
{
public:
  int seed;
  std::mt19937 mt;

  MtRandomizer(int seed);
  float getRndFloat(float from, float to) override;
  int getRndInt(int from, int to) override;
};
