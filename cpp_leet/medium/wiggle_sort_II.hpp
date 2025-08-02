#pragma once

#include "../imports.hpp"

#if 1

class Solution {
public:
    void wiggleSort(std::vector<int>& nums) {
        std::priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 1; i < (int)nums.size(); i += 2) {
            nums[i] = q.top();
            q.pop();
        }
        for (int i = 0; i < (int)nums.size(); i += 2) {
            nums[i] = q.top();
            q.pop();
        }
    }
};

#endif
