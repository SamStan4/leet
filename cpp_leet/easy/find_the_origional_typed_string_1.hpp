#pragma once

#include "./../imports.hpp"

class Solution
{
public:
  int possibleStringCount(string word)
  {
    const size_t word_size = word.size();

    int total = 1;

    for (size_t i = 1; i < word_size; ++i)
    {
      if (word[i] == word[i - 1])
      {
        ++total;
      }
    }

    return total;
  }
};