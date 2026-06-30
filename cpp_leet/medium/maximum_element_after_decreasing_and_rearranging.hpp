// NOLINTBEGIN(misc-definitions-in-headers)

#include <algorithm>
#include <vector>

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr);
};

int Solution::maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr)
{
    std::sort(arr.begin(), arr.end());

    arr[0] = 1;

    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] - arr[i - 1] > 1)
        {
            arr[i] = arr[i - 1] + 1;
        }
    }

    return arr.back();
}

// NOLINTEND(misc-definitions-in-headers)