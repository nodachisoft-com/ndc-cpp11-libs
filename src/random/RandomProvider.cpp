#include "RandomProvider.hpp"
#include "MtRandomizer.hpp"

IRandomizer *RandomProvider::getRandomizer(RND_TYPE type, int seed)
{
  IRandomizer *rand = NULL;
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
