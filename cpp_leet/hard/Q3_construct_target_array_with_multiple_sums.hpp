#include <vector>
#include <queue>
#include <numeric>

class Solution {
  public:
    bool isPossible(std::vector<int>& target);
};

bool Solution::isPossible(std::vector<int>& target) {

  // This value stores the current sum of the values in the vector.
  long long sum = 0ll;

  // This max heap is going to be used to select the max element from the vector of numbers.
  std::priority_queue<int> pq;

  // Sum up the sum variable and pushing all the values to the max heap.
  for (const v : target) {
    sum += static_cast<long long>(v);
    pq.push(v);
  }

  while (!pq.empty()) {

    sum -= static_cast<long long>(pq.top());

    
  }

  return true;
}

/*

  [9, 3, 5]

  9 + 3 + 5 = 17

  1 = 9 - (17 - 9)








*/