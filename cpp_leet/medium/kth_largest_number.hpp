#include <algorithm>
#include <string>
#include <vector>
#include <functional>

class Solution {
public:
  std::string kthLargestNumber(std::vector<std::string>& nums, int k);
};

std::string Solution::kthLargestNumber(std::vector<std::string>& nums, int k) {
  const std::function<bool(const std::string&, const std::string&)> sortFunc = [](const std::string& a, const std::string& b) -> bool {
    if (a.size() != b.size()) return a.size() > b.size();
    return a > b;
  };
  std::sort(nums.begin(), nums.end(), sortFunc);
  return nums[k-1];
}