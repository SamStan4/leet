#include <vector>
#include <queue>

class Solution {
  public:
    int lastStoneWeight(std::vector<int>& stones);
};

int Solution::lastStoneWeight(std::vector<int>& stones) {
  std::priority_queue<int> pq(stones.begin(), stones.end());
  while (pq.size() > 1ul) {
    const int s1 = pq.top(); pq.pop();
    const int s2 = pq.top(); pq.pop();
    const int dif = s1 - s2;
    if (dif > 0) pq.push(dif);
  }
  return pq.empty() ? 0 : pq.top();
}