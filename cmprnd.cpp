#include <iostream>
#include <time.h>
#include <vector>
#include <random>
int main()
{
  const int N = 1000;
  {
    srand((int)time(0));
    int sum = 0;  // Σx
    int sum2 = 0; // Σx^2
    for (int i = 0; i < N; ++i)
    {
      int r = rand() % 100;
      sum += r;
      sum2 += r * r;
    }
    double ave = (double)sum / N;
    std::cout << "ave = " << ave << "\n";
    std::cout << "σ = " << sqrt((double)sum2 / N - ave * ave) << "\n";
  }
  {
    int sum = 0;                                    // Σx
    int sum2 = 0;                                   // Σx^2
    std::random_device rnd;                         // 非決定的な乱数生成器を生成
    std::mt19937 mt(rnd());                         //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
    std::uniform_int_distribution<> rand100(0, 99); // [0, 99] 範囲の一様乱数
    for (int i = 0; i < N; ++i)
    {
      int r = rand100(mt);
      sum += r;
      sum2 += r * r;
    }
    double ave = (double)sum / N;
    std::cout << "ave = " << ave << "\n";
    std::cout << "σ = " << sqrt((double)sum2 / N - ave * ave) << "\n";
  }
  getchar();
  return 0;
}
