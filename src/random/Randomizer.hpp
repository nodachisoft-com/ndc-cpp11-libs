#pragma once

/**
 * 乱数生成器の I/F
 */
class Randomizer
{
public:
  virtual ~Randomizer(){};

  virtual float getRndFloat(float from, float to) = 0;

  virtual int getRndInt(int from, int to) = 0;

  // virtual int getRndIntRange( From-To-Array[]) : int
  // getRndFloatRange(From - To - Aarray[]) : float
};
