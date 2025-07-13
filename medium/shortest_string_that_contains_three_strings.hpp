#pragma once

#include "./../imports.hpp"

class Solution
{
private:
  static std::string combineStrings(const std::string& l, const std::string& r)
  {
    const int lSize = static_cast<int>(l.size());
    const int rSize = static_cast<int>(r.size());
    
    int s = 0;

    for (bool g = true; ; ++s)
    {
      for (int i = s, j = 0; ; ++i, ++j)
      {
        if (i == lSize || j == rSize)
        {
          g = false;
          break;
        }
        else if (l[i] != r[j])
        {
          break;
        }
      }

      if (!g)
      {
        break;
      }
    }

    int i = 0;

    std::string answer;
    answer.reserve(lSize + rSize);

    for (; i < s; ++i)
    {
      answer.push_back(l[i]);
    }

    for (int j = 0; j < rSize; ++i, ++j)
    {
      answer.push_back(r[j]);
    }

    for (; i < lSize; ++i)
    {
      answer.push_back(l[i]);
    }

    return answer;
  }

  void tryCombinations(const std::string** stringList, const bool* )
  {

  }

public:
  string minimumString(std::string a, std::string b, std::string c)
  {
    if (a > b) std::swap(a, b);
    if (b > c) std::swap(b, c);
    if (a > b) std::swap(a, b);
    
    std::string* list[3] = { &a, &b, &c };

    bool used[3] = { false };


  }
};