#include "../imports.hpp"

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minSum = nums[0], curMinSum = nums[0];
        int maxSum = nums[0], curMaxSum = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            curMinSum = std::min(curMinSum + nums[i], nums[i]);
            minSum = std::min(minSum, curMinSum);
            curMaxSum = std::max(curMaxSum + nums[i], nums[i]);
            maxSum = std::max(maxSum, curMaxSum);
        }
        return std::max(std::abs(minSum), std::abs(maxSum));
    }
};