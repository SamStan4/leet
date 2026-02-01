#include <vector>
#include <queue>

class Solution {
  public:
    int timeRequiredToBuy(const std::vector<int>& tickets, int k);
};

#if 0

int Solution::timeRequiredToBuy(const std::vector<int>& tickets, int k) {
  const int n = static_cast<int>(tickets.size());
  std::queue<std::pair<int, int>> q;
  for (int i = 0; i < n; ++i) q.emplace(i, tickets[i]);
  for (int i = 1; ; ++i) {
    auto front = q.front();
    q.pop();
    --front.second;
    if (front.second <= 0) {
      if (front.first == k) return i;
    } else {
      q.push(front);
    }
  }
  return -1;
}

#else

int Solution::timeRequiredToBuy(const std::vector<int>& tickets, int k) {
  const int n = static_cast<int>(tickets.size());
  int answer = 0;
  for (int i = 0; i < n; ++i) {
    answer += std::min(tickets[i], tickets[k] - (i > k ? 1 : 0));
  }
  return answer;
}

#endif