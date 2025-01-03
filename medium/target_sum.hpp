#pragma once

#include "../imports.hpp"

#if 0

class Solution {
private:
    int solver(vector<int>& nums, int index, int sum, int target) {
        if (index == nums.size()) {
            return sum == target ? 1 : 0;
        }
        return this->solver(nums, index + 1, sum + nums[index], target) + this->solver(nums, index + 1, sum - nums[index], target);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return this->solver(nums, 0, 0, target);
    }
};

#else

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
    }
};

#endif