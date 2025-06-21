#include "./../imports.hpp"

class Solution {
public:
  int minimumDeletions(std::string word, int k) {
    size_t counts[26] = { 0 };
    for (size_t i = 0; i < word.size(); ++i)
      ++counts[word[i]-'a'];
    size_t min_del = std::numeric_limits<int>::max();
    for (size_t i = 0; i < 26; ++i) {
      if (counts[i] == 0)
        continue;
      size_t num_del = 0;
      const size_t max_count = counts[i] + k;
      for (size_t j = 0; j < 26; ++j) {
        if (i == j || counts[j] == 0)
          continue;
        if (counts[j] < counts[i])
          num_del += counts[j];
        else if (counts[j] > max_count)
          num_del += counts[j] - max_count;
      }
      min_del = std::min(min_del, num_del);
    }
    return static_cast<int>(min_del);
  }
};