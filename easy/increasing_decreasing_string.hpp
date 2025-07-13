#pragma once

#include "./../imports.hpp"

class Solution {
public:
  std::string sortString(std::string s) {       
    int sSize = static_cast<int>(s.size());
    int counts[26] = { 0 };
    for (int i = 0; i < sSize; ++i) {
      ++counts[s[i]- 'a' ];
    }
    std::string answer;
    answer.reserve(sSize);
    while (sSize > 0) {
      for (int i = 0; i < 26; ++i) {
        if (counts[i] > 0) {
          answer.push_back('a' + i);
          --sSize;
          --counts[i];
        }
      }
      for (int i = 25; i >= 0; --i) {
        if (counts[i] > 0) {
          answer.push_back('a' + i);
          --sSize;
          --counts[i];
        }
      }
    }
    return answer;
  } 
};
