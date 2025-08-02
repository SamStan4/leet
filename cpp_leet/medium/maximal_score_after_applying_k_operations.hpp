#pragma once

#include "./../imports.hpp"

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> numberQueue(nums.begin(), nums.end());
        long long score = 0;
        for (int i = 0; i < k; ++i) {
            int temp = numberQueue.top();
            numberQueue.pop();
            score += temp;
            numberQueue.push((temp + 2) / 3);
        }
        return score;
    }
};

static int init = []() {
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();