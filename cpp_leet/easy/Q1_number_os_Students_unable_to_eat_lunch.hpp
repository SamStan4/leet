#include <vector>
#include <queue>

class Solution {
  public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches);
};

int Solution::countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
  std::queue<int> q{};
  for (const int student : students) q.push(student);
  size_t i = 0, j = 0;
  do {
    i = q.size();
    for (size_t k = 0; !q.empty() && k < i; ++k) {
      if (q.front() != sandwiches[j]) {
        q.push(q.front());
      } else {
        ++j;
      }
      q.pop();
    }
  } while (q.size() < i);
  return static_cast<int>(q.size());
}