#include "./../imports.hpp"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], curSum = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            curSum = std::max(curSum + nums[i], nums[i]);
            maxSum = std::max(curSum, maxSum);
        }        
        return maxSum;
    }
};