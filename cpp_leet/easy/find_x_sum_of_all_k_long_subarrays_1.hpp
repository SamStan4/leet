#include <vector>
#include <unordered_map>
#include <queue>

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
  int calculateXSum(
    const std::vector<int>& nums,
    const int idx,
    const int k,
    const int x);
public:
  std::vector<int> findXSum(
    const std::vector<int>& nums,
    int k,
    int x);
};

int Solution::calculateXSum(
  const std::vector<int>& nums,
  const int idx,
  const int k,
  const int x) {

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

  int xSum = 0;
  while (!q.empty()) {
    xSum += q.top().first * q.top().second;
    q.pop();
  }

  return xSum;
}

std::vector<int> Solution::findXSum(
  const std::vector<int>& nums,
  int k,
  int x) {

  const int n = static_cast<int>(nums.size());
  std::vector<int> xSumVector;
  xSumVector.reserve(n - k + 1);

  for (int i = 0, j = k - 1; j < n; ++i, ++j) {
    xSumVector.push_back(this->calculateXSum(nums, i, k, x));
  }

  return std::move(xSumVector);
}