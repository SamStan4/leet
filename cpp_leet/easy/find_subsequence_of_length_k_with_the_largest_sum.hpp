#include "./../imports.hpp"

class Solution {
public:
  std::vector<int> maxSubsequence(std::vector<int>& nums, int k)
  {
    std::priority_queue
    <
      std::pair<int, int>,
      std::vector<std::pair<int, int>>,
      std::greater<std::pair<int, int>>
    > q;

    std::vector<bool> c(nums.size(), false);

    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
    {
      if (static_cast<int>(q.size()) < k)
      {
        c[i] = true;
        q.push(std::make_pair(nums[i], i));
      }
      else if (q.top().first < nums[i])
      {
        c[q.top().second] = false;
        q.pop();

        c[i] = true;
        q.push(std::make_pair(nums[i], i));
      }
    }

    std::vector<int> a(k);

    for (int i = 0, j = 0; i < static_cast<int>(nums.size()); ++i)
    {
      if (c[i])
      {
        a[j++] = nums[i];
      }
    }

    return a;
  }
};