#include <random>
#include "MtRandomizer.hpp"

MtRandomizer::MtRandomizer(int _seed)
{
  seed = _seed;
  mt = std::mt19937(_seed);
}

float MtRandomizer::getRndFloat(float from, float to)
{
  std::uniform_real_distribution<> dist(from, to);
  return dist(mt);
}

int MtRandomizer::getRndInt(int from, int to)
{
  std::uniform_int_distribution<> dist(from, to);
  return dist(mt);
}
