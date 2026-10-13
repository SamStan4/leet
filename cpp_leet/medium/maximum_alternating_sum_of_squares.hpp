#include <algorithm>
#include <cmath>
#include <vector>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums);
};

// NOLINTBEGIN(misc-definitions-in-headers)

long long Solution::maxAlternatingSum(std::vector<int>& nums) {

    const int n = static_cast<int>(nums.size());

    std::sort(
        nums.begin(),
        nums.end(),
        [](const int a, const int b) -> bool {
            return std::abs(a) < std::abs(b);
        }
    );

    long long answer = 0;

    for (
        int i = 0, j = n / 2;
        j < n;
        ++i, ++j
    ) {
        answer -= nums[i] * nums[i];
        answer += nums[j] * nums[j];
    }

    if (n % 2) {
        const int m = n / 2;
        answer += nums[m] * nums[m];
    }

    return answer;
}

// NOLINTEND(misc-definitions-in-headers)