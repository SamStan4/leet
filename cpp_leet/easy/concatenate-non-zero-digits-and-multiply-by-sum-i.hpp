// NOLINTBEGIN(misc-definitions-in-headers)

#include <iostream>
#include <ios>

class Solution
{
public:
  static long long sumAndMultiply(int n);
};

long long Solution::sumAndMultiply(
  int n)
{
  int digits_concatenated = 0;
  int digits_sum          = 0;
  int multiplier = 1;

  while (n > 0)
  {
    int digit = n % 10;

    if (digit != 0)
    {
      digits_concatenated += digit * multiplier;

      digits_sum += digit;

      multiplier *= 10;
    }

    n /= 10;
  }

  return (
    static_cast<long long>(digits_concatenated) *
    static_cast<long long>(digits_sum)
  );
}

static int init = []() -> int
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
} ();

// NOLINTEND(misc-definitions-in-headers)