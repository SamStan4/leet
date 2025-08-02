#pragma once

#include "./../imports.hpp"

class Solution
{
private:
  static constexpr int mod = 1e9 + 7;

  /**
   * binary search, finds the index of the last element that is less than or equal to maxElement
   * nums is sorted ascending
   */
  int findMaxElement(const std::vector<int>& nums, const int max_element)
  {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    int result = -1;

    while (left <= right)
    {
      const int mid = left + (right - left) / 2;

      if (nums[mid] <= max_element)
      {
        result = mid;
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }

    return result;
  }
public:
  int numSubseq(std::vector<int>& nums, const int target)
  {
    std::sort(nums.begin(), nums.end());

    int count = 0;

    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
    {
      const int max_element = target - nums[i];

      const int found_index = this->findMaxElement(nums, max_element);

      static constexpr int mod = 1e9 + 7;

      if (found_index >= i)
      {
        const int power = found_index - i;

        const long long add_on = std::pow(2, static_cast<long long>(power)) % this->mod;


      }
    }

    return count;
  }
};