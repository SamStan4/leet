#include <vector>
#include <limits>
#include <algorithm>

class Solution
{
public:
  int minRemoval(
    std::vector<int>& nums,
    const int k);
};

int Solution::minRemoval(
  std::vector<int>& nums,
  const int k)
{
  const int n = static_cast<int>(nums.size());
  int ans = std::numeric_limits<int>::max();
  const long long llK = static_cast<long long>(k);
  
  std::sort(nums.begin(), nums.end());

  for (int i = 0, j = 0; j < n; ++j)
  {
    while (static_cast<long long>(nums[i]) * llK < static_cast<long long>(nums[j]))
    {
      ++i;
    }

    ans = std::min(ans, i + n - j - 1);
  }

  return ans;
}