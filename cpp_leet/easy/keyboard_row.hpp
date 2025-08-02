#pragma once

#include "./../imports.hpp"

class Solution
{
public:
  std::vector<std::string> findWords(std::vector<std::string>& words)
  {
    static const int row_mapping[26] = { 1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2 };
    
    std::vector<std::string> good_words;

    for (size_t i = 0; i < words.size(); ++i)
    {
      bool is_good_flag = true;

      for (size_t j = 1; j < words[i].size(); ++j)
      {
        const int c_one_map = row_mapping[std::tolower(words[i][j]) - 'a'];
        const int c_two_map = row_mapping[std::tolower(words[i][j - 1]) - 'a'];

        if (c_one_map != c_two_map)
        {
          is_good_flag = false;
          break;
        }
      }

      if (is_good_flag)
      {
        good_words.push_back(words[i]);
      }
    }

    return good_words;
  }
};