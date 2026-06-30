// NOLINTBEGIN(misc-definitions-in-headers)

#include <vector>
#include <unordered_map>

class Solution
{
public:
    int maximumLength(std::vector<int>& nums);
};

int Solution::maximumLength(std::vector<int>& nums)
{
    std::unordered_map<int, int> freq;

    for (size_t i{0}; i < nums.size(); ++i)
    {
        ++freq[nums[i]];
    }

    int max_length = 0;

    for (auto it = freq.begin(); it != freq.end(); ++it)
    {
        
        if (it->first == 1)
        {
            continue;
        }


    }
}

// NOLINTEND(misc-definitions-in-headers)