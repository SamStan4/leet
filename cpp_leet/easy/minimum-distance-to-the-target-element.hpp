#include <cmath>
#include <limits>
#include <vector>

class Solution {
public:
    int getMinDistance(const std::vector<int>& nums, const int target, const int start) {
        const int n = static_cast<int>(nums.size());
        int minDistance = std::numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                minDistance = std::min(minDistance, std::abs(i - start));
            }
        }
        return minDistance;
    }
};