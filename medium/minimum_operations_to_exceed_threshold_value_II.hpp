#pragma once

#include "./../imports.hpp"

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        int numOps = 0;
        while (pq.size() >= 2 && pq.top() < k) {
            const int x = pq.top();
            pq.pop();
            const int y = pq.top();
            pq.pop();
            const long long result = (long long)min(x, y) * 2 + (long long)max(x, y);
            pq.push(min((long long)k, result));
            ++numOps;
        }
        return numOps;
    }
};
