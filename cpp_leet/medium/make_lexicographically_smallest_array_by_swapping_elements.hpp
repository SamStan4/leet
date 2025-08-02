#pragma once

#include "./../imports.hpp"

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        sort(nums.begin(), nums.end(), [limit](const int& n1, const int& n2) {
            if (abs(n1 - n2) > limit) {
                return false;
            }
            return n1 < n2;
        });
        return nums;
    }
};