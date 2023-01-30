#include <random>
#include "IRandomizer.hpp"
#include "MtRandomizer.hpp"

MtRandomizer::MtRandomizer(int seed)
{
  this->seed = seed;
  mt = std::mt19937(seed);
}

float MtRandomizer::getRndFloat(float from, float to)
{
  std::uniform_real_distribution<> dist(0.0, 1.0);
  return dist(mt);
}

int MtRandomizer::getRndInt(int from, int to)
{
  std::uniform_int_distribution<> dist(from, to);
  return dist(mt);
}
