#include <vector>

class Solution {
  public:
    std::vector<long long> sumOfThree(long long num);
};

std::vector<long long> Solution::sumOfThree(long long num) {
  std::vector<long long> answer;
  answer.reserve(3);
  if (num % 3ll != 0ll) return answer;
  const long long baseNum = (num / 3ll) - 1ll;
  answer.push_back(baseNum);
  answer.push_back(baseNum + 1ll);
  answer.push_back(baseNum + 2ll);
  return answer;
}