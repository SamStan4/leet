#pragma once

#include "./../imports.hpp"

class Solution
{
public:
  int maxEvents(std::vector<std::vector<int>>& events)
  {
    static const std::function<bool(const std::vector<int>, const std::vector<int>)> sort_function = [](const std::vector<int>& a, const std::vector<int>& b) -> bool
    {
      assert(a.size() == 2);
      assert(b.size() == 2);

      if (a[0] != b[0])
      {
        return a[0] < b[0];
      }

      return a[1] < b[1];
    };

    std::sort(events.begin(), events.end(), sort_function);

    

    return 0;
  }
};