// NOLINTBEGIN(misc-definitions-in-headers)

#include <vector>
#include <algorithm>

class Solution
{
public:
    static int minimumCost(
        std::vector<int>& cost);
};

int Solution::minimumCost(
    std::vector<int>& cost)
{
    std::sort(cost.begin(), cost.end(), std::greater<int>());

    int totalCost = 0;

    for (size_t i = 0; i < cost.size(); ++i)
    {
        if (i % 3ul == 2) continue;

        totalCost += cost[i];
    }

    return totalCost;
}


// NOLINTEND(misc-definitions-in-headers)