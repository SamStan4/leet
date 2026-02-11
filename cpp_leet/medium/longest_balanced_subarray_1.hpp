#include <iostream>
#include <ios>
#include <vector>
#include <unordered_set>

// This solution is no good, time fails.
// not sure why leetcode suggested this approach...

class Solution
{
private:

    static bool isBalanced(const std::vector<int>& nums, const int start, const int end)
    {
        std::unordered_set<int> oddSet;
        std::unordered_set<int> evenSet;
        
        for (int i = start; i <= end; ++i)
        {
            if (nums[i] & 1)
            {
                oddSet.insert(nums[i]);
            }
            else
            {
                evenSet.insert(nums[i]);
            }
        }

        return oddSet.size() == evenSet.size();
    }

public:

    static int longestBalanced(const std::vector<int>& nums)
    {
        const int n = static_cast<int>(nums.size());
        int maxSize = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (Solution::isBalanced(nums, i, j))
                {
                    maxSize = std::max(maxSize, j - i + 1);
                }
            }
        }

        return maxSize;
    }
};


static int init = []() -> int
{
    std::ios_base::sync_with_stdio(false),
        std::cin.tie(nullptr),
        std::cout.tie(nullptr);
    return 0;
} ();