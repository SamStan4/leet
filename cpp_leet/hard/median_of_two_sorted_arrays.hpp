#pragma once

#include "../imports.hpp"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            swap(nums1, nums2);
        }
    }
};