#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <ios>

class Solution {
private:
  /**
   * @brief calculates the x-sum
   * 
   * @param nums 
   * @param idx 
   * @param k 
   * @param x 
   * @return int 
   */
  long long calculateXSum(
    const std::vector<int>& nums,
    const int idx,
    const int k,
    const int x) noexcept;
public:
  /**
   * @brief leetcode: find-x-sum-of-all-k-long-subarrays-ii
   */
  std::vector<long long> findXSum(
    const std::vector<int>& nums,
    int k,
    int x) noexcept;
};

long long Solution::calculateXSum(
  const std::vector<int>& nums,
  const int idx,
  const int k,
  const int x) noexcept {

  const int n = static_cast<int>(nums.size());
  std::unordered_map<int, int> freqTable;

  for (int i = idx, j = 0; i < n && j < k; ++i, ++j)
    ++freqTable[nums[i]];
  
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
  for (auto it = freqTable.begin(); it != freqTable.end(); ++it) {
    const std::pair<int, int> p = std::make_pair(it->second, it->first);
    if (static_cast<int>(q.size()) < x)
      q.push(p);
    else if (p.first > q.top().first || (p.first == q.top().first && p.second > q.top().second)) {
      q.pop();
      q.push(p);
    }
  }
  long long xSum = 0;
  while (!q.empty()) {
    xSum += static_cast<long long>(q.top().first) * static_cast<long long>(q.top().second);
    q.pop();
  }

  return xSum;
}

std::vector<long long> Solution::findXSum(
  const std::vector<int>& nums,
  int k,
  int x) noexcept {

  const int n = static_cast<int>(nums.size());
  std::vector<long long> xSumVector;
  xSumVector.reserve(n - k + 1);

  for (int i = 0, j = k - 1; j < n; ++i, ++j) {
    xSumVector.push_back(this->calculateXSum(nums, i, k, x));
  }

  return std::move(xSumVector);
}

static int init = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
  return 0;
} ();