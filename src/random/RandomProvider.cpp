#include "RandomProvider.hpp"
#include "Randomizer.hpp"
#include "MtRandomizer.hpp"

Randomizer *RandomProvider::getRandomizer(RND_TYPE type, uint seed)
{
  Randomizer *rand = NULL;
  switch (type)
  {
  case RND_TYPE::LINEAR:
    rand = new MtRandomizer(0);
    break;
  case RND_TYPE::MT19937:
    rand = new MtRandomizer(0);
    break;
  }
  return rand;
};
