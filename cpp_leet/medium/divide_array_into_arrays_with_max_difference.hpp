#include <vector>
#include <algorithm>
#include <iostream>
#include <ios>

class Solution {
  public:
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k);
};

#if 0

std::vector<std::vector<int>> Solution::divideArray(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<int>> answer;
  answer.reserve(n / 3);
  for (int i = 2; i < n; i += 3) {
    const int num1 = nums.at(i - 2);
    const int num2 = nums.at(i - 1);
    const int num3 = nums.at(i);
    if ((num3 - num1) > k) return {};
    answer.push_back({num1, num2, num3});
  }
  return answer;
}

#else

std::vector<std::vector<int>> Solution::divideArray(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<int>> answer(n / 3, std::vector<int>(3));
  for (int i = 2, j = 0; i < n; i += 3, ++j) {
    const int num1 = nums.at(i - 2);
    const int num2 = nums.at(i - 1);
    const int num3 = nums.at(i);
    if ((num3 - num1) > k) return {};
    answer[j][0] = num1;
    answer[j][1] = num2;
    answer[j][2] = num3;
  }
  return answer;
}

#endif

static int init = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
  return 0;
} ();