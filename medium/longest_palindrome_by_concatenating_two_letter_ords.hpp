#include "./../imports.hpp"

#if 0

// This one is slightly slower, works good tho when looking at memory

class Solution {
public:
  int longestPalindrome(std::vector<std::string>& words) {
    std::unordered_map<std::string, int> nonHomoSet;
    int homoSet = 0;
    int len = 0;
    for (size_t i = 0; i < words.size(); ++i) {
      if (words[i][0] == words[i][1]) {
        // homogenuous
        const int setBit = 1 << (words[i][0] - 'a');
        if (homoSet & setBit) {
          len += 4;
          homoSet ^= setBit;
        } else {
          homoSet |= setBit;
        }
      } else {
        // non homogenuous
        const std::string wordRev = { words[i][1], words[i][0] };
        if (nonHomoSet.find(wordRev) != nonHomoSet.end() && nonHomoSet[wordRev] > 0) {
          len += 4;
          --nonHomoSet[wordRev];
        } else {
          ++nonHomoSet[words[i]];
        }
      }
    }
    if (homoSet) {
      len += 2;
    }
    return len;
  }
};

#else

// This solution is super fast, all stack memory and no string hashing

class Solution {
public:
  int longestPalindrome(vector<string>& words) {
    int counts[26][26] = { { 0 } };
    for (size_t i = 0; i < words.size(); ++i) {
      ++counts[words[i][0] - 'a'][words[i][1] - 'a'];
    }
    int length = 0;
    int add = 0;
    for (size_t i = 0; i < 26; ++i) {
      if (counts[i][i] & 1) {
        --counts[i][i];
        add = 2;
      }
      length += counts[i][i] * 2;
      for (size_t j = i + 1; j < 26; ++j) {
        length += std::min(counts[i][j], counts[j][i]) * 4;
      }
    }
    return length + add;
  }
};

static int init = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
  return 0;
} ();

#endif