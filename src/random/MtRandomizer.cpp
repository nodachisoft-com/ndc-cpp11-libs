#include <random>
#include "Randomizer.hpp"
#include "MtRandomizer.hpp"

// int MtRandomizer::seed;

MtRandomizer::MtRandomizer(int seed)
{
  // std::mt19937 mt((int)time(0));
  // std::mt19937 aa(seed);
  // mt = new std::mt19937(seed);
  mt = std::mt19937(seed);
}

float MtRandomizer::getRndFloat(float from, float to) // override
{
  std::uniform_real_distribution<> dist(0.0, 1.0);
  return dist(mt);
  // return 0.5f;
}

int MtRandomizer::getRndInt(int from, int to) // override
{
  std::uniform_int_distribution<> dist(from, to);
  return dist(mt);
}
