#include <vector>
#include <string>

class Solution {
  private:
    static constexpr char* push{"Push"};
    static constexpr char* pop {"Pop"};
  public:
    std::vector<std::string> buildArray(
      std::vector<int>& target, int n);
};

std::vector<std::string> Solution::buildArray(
  std::vector<int>& target, int n) {
  const int targetSize = static_cast<int>(target.size());
  int i = 1;
  int j = 0;
  std::vector<std::string> ans;
  while (i < n, j < targetSize) {
    ans.emplace_back(Solution::push);
    if (i == target[j]) {
      ++j;
    } else {
      ans.emplace_back(Solution::pop);
    }
    ++i;
  }
  ans.reserve(ans.size() + static_cast<size_t>(targetSize - j));
  while (j < targetSize) {
    ans.emplace_back(Solution::push);
    ans.emplace_back(Solution::pop);
    ++j;
  }
  return ans;
}