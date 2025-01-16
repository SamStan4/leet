#pragma once

#include "../imports.hpp"

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int answer = 0;
        if (nums2.size() % 2) {
            for (int i = 0; i < nums1.size(); ++i) {
                answer ^= nums1[i];
            }
        }
        if (nums1.size() % 2) {
            for (int i = 0; i < nums2.size(); ++i) {
                answer ^= nums2[i];
            }
        }
        return answer;
    }
};