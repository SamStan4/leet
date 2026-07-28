// NOLINTBEGIN(misc-definitions-in-headers)

#include <limits>
#include <vector>
#include <algorithm>

#if 0

class Solution {
public:
    static int maximumProduct(std::vector<int>& nums);
};

int Solution::maximumProduct(std::vector<int>& nums) {

    int i = std::numeric_limits<int>::min(); // largest
    int j = std::numeric_limits<int>::min(); // 2nd largest
    int k = std::numeric_limits<int>::min(); // 3rd largest
    int l = std::numeric_limits<int>::min(); // smallest
    int m = std::numeric_limits<int>::min(); // smallest

    for (int n : nums)
    {
        // Choose for largest

        if (n > i) std::swap(n, i);
        if (n > j) std::swap(n, j);
        
    }
}

#else

class Solution {
public:
    static int maximumProduct(std::vector<int>& nums);
};

int Solution::maximumProduct(std::vector<int>& nums) {

    const int n = static_cast<int>(nums.size());

    std::sort(nums.begin(), nums.end());

    const int candidate_one = nums[0] * nums[1] * nums[n - 1];
    const int candidate_two = nums[n - 1] * nums[n - 2] * nums[n - 3];

    return std::max(candidate_one, candidate_two);
}

#endif

/*

[[0, 1, 2, 3, 4, 5]



*/

// NOLINTEND(misc-definitions-in-headers)