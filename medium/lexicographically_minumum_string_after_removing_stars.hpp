#include "./../imports.hpp"

class Solution {
public:
  std::string clearStars(std::string s) {
    std::vector<int> letters[26];
    const int sSize = static_cast<int>(s.size());
    for (int i = 0; i < sSize; ++i) {
      if (s[i] == '*') {
        for (int j = 0; j < 26; ++j) {
          if (!letters[j].empty()) {
            letters[j].pop_back();
            break;
          }
        }
      } else {
        letters[s[i]-'a'].push_back(i);
      }
    }
    std::string answer;
    answer.reserve(s.size());
    for (int i = sSize - 1; i >= 0; --i) {
      const int index = static_cast<int>(s[i]-'a');
      if (s[i] != '*' && !letters[index].empty() && letters[index].back() == i) {
        answer.push_back(s[i]);
        letters[index].pop_back();
      }
    }
    std::reverse(answer.begin(), answer.end());
    return answer;
  }
};

int fast_io = []() {
  std::ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
  return 0;
} ();