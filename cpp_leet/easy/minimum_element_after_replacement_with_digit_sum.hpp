// NOLINTBEGIN(misc-definitions-in-headers)

#include <iostream>
#include <ios>
#include <limits>
#include <vector>

class Solution {
public:
    static int minElement(
        std::vector<int>& nums);
};

int Solution::minElement(
    std::vector<int>& nums)
{
    int m = std::numeric_limits<int>::max();

    for (int n : nums)
    {
        int s = 0;

        while (n > 0)
        {
            s += n % 10;
            n /= 10;
        }

        m = std::min(m, s);
    }

    return m;
}

static int init = []() -> int
{
    std::ios_base::sync_with_stdio(false),
        std::cin.tie(nullptr),
        std::cout.tie(nullptr);
    return 0;
} ();

// NOLINTEND(misc-definitions-in-headers)