#include <vector>
#include <string>

class Solution {
public:
  int maximumNumberOfStringPairs(std::vector<std::string>& words);
};

int Solution::maximumNumberOfStringPairs(std::vector<std::string>& words) {
  const int n = static_cast<int>(words.size());
  int num = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if (words[i][0] == words[j][1] && words[i][1] == words[j][0])
        ++num;
  return num;
}