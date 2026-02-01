#include <vector>
#include <queue>
#include <tuple>
#include <set>

class Solution {
  public:
    std::vector<std::vector<int>> kSmallestPairs(
      std::vector<int>& nums1,
      std::vector<int>& nums2,
      int k);
};

std::vector<std::vector<int>> Solution::kSmallestPairs(
  std::vector<int>& nums1,
  std::vector<int>& nums2,
  int k) {

  std::priority_queue<
    std::tuple<int, int, int>,
    std::vector<std::tuple<int, int, int>>,
    std::greater<std::tuple<int, int, int>>> pq{};
  std::set<std::pair<int, int>> used{};
  std::vector<std::vector<int>> answer{}; answer.reserve(k);

  pq.emplace(nums1[0] + nums2[0], 0, 0);
  used.emplace(0, 0);

  while (!pq.empty() && answer.size() < static_cast<size_t>(k)) {

    auto [sum, numsOneIdx, numsTwoIdx] = pq.top(); pq.pop();

    answer.push_back({nums1[numsOneIdx], nums2[numsTwoIdx]});

    if (
      numsOneIdx + 1 < static_cast<int>(nums1.size()) &&
      used.find(std::make_pair(numsOneIdx + 1, numsTwoIdx)) == used.end()) {

      pq.emplace(nums1[numsOneIdx + 1] + nums2[numsTwoIdx], numsOneIdx + 1, numsTwoIdx);
      used.emplace(numsOneIdx + 1, numsTwoIdx);
    }

    if (
      numsTwoIdx + 1 < static_cast<int>(nums2.size()) &&
      used.find(std::make_pair(numsOneIdx, numsTwoIdx + 1)) == used.end()) {

      pq.emplace(nums1[numsOneIdx] + nums2[numsTwoIdx + 1], numsOneIdx, numsTwoIdx + 1);
      used.emplace(numsOneIdx, numsTwoIdx + 1);
    }
  }

  return answer;
}