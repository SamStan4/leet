#include <vector>

class Solution
{
  public:

    static long long getDescentPeriods
    (
      const std::vector<int>& prices
    ) noexcept;
};

long long Solution::getDescentPeriods
(
  const std::vector<int>& prices
) noexcept
{
  long long numSmoothDescents{0};
  long long span{1};

  for (std::size_t i{1}; i < prices.size(); ++i)
  {
    if (prices[i] == prices[i - 1] - 1)
    {
      ++span;
    }
    else
    {
      numSmoothDescents += (span * (span + 1ll)) / 2ll;

      span = 1ul;
    }
  }

  numSmoothDescents += (span * (span + 1ll)) / 2ll;

  return numSmoothDescents;
}