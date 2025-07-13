#include "./../imports.hpp"

#if 0

// reverse sort method
class Solution {
public:
  int matchPlayersAndTrainers(std::vector<int>& players, std::vector<int>& trainers) {
    const int n = (int)players.size();
    const int m = (int) trainers.size();
    static const std::function<bool(int, int)> sort_func = [](const int a, const int b) -> bool {
      return a > b;
    };
    std::sort(players.begin(), players.end(), sort_func);
    std::sort(trainers.begin(), trainers.end(), sort_func);
    int total = 0;
    for (int i = 0, j = 0; i < n && j < m; ++i) {
      if (players[i] <= trainers[j]) {
        ++j;
        ++total;
      }
    }
    return total;
  }
};

#elif 1

// regular sorting
class Solution {
public:
  int matchPlayersAndTrainers(std::vector<int>& p, std::vector<int>& t) {
    std::sort(p.begin(), p.end());
    std::sort(t.begin(), t.end());
    const int n = (int)p.size();
    const int m = (int)t.size();
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
      if (p[i] <= t[j]) {
        ++i;
      }
      ++j;
    }
    return i;
  }
};

#else

// with a priority queue
class Solution {
public:
  int matchPlayersAndTrainers(std::vector<int>& p, std::vector<int>& t) {
    std::priority_queue<int, std::vector<int>, std::greater<int>>
      pq(p.begin(), p.end()),
      tq(t.begin(), t.end());
    int total = 0;
    while (!pq.empty() && !tq.empty()) {
      if (pq.top() <= tq.top()) {
        pq.pop();
        ++total;
      }
      tq.pop();
    }
    return total;
  }
};

#endif

int fast_io = []() -> int {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr), std::cout.tie(nullptr);
  return 0;
}();
