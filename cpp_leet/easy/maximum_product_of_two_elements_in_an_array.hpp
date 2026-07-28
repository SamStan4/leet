// NOLINTBEGIN(misc-definitions-in-headers)

#include <vector>
#include <limits>

class Solution {
public:
    int maxProduct(const std::vector<int>& nums);
};

int Solution::maxProduct(const std::vector<int>& nums) {

    int minOne = std::numeric_limits<int>::max();
    int minTwo = std::numeric_limits<int>::max();

    int maxOne = std::numeric_limits<int>::min();
    int maxTwo = std::numeric_limits<int>::min();

    for (const int n : nums) {

        // Try for the minimum

        int minCandidate = n;

        if (minOne > minCandidate) std::swap(minCandidate, minOne);
        if (minTwo > minCandidate) std::swap(minCandidate, minTwo);

        // Try for the maximum

        int maxCandidate = n;

        if (maxOne < maxCandidate) std::swap(maxCandidate, maxOne);
        if (maxTwo < maxCandidate) std::swap(maxCandidate, maxTwo);
    }

    --minOne;
    --minTwo;
    --maxOne;
    --maxTwo;

    return std::max(minOne * minTwo, maxOne * maxTwo);
}

// NOLINTEND(misc-definitions-in-headers)