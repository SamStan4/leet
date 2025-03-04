#pragma once

#include "./../imports.hpp"

class Solution {
private:
    int f(int n) {
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
public:
    int maximumSum(vector<int>& nums) {
        const size_t n = nums.size();
        unordered_map<int, pair<int, int>> m;
        for (size_t i = 0; i < n; ++i) {
            const int s = this->f(nums[i]);
            if (m.find(s) == m.end()) m[s] = {-1, -1};
            pair<int, int>& p = m[s];
            if (p.second < nums[i]) {
                p.second = nums[i];
                if (p.second > p.first) swap(p.first, p.second);
            }
        }
        int maxPair = -1;
        for (const auto& p : m)
            if (p.second.first != -1 && p.second.second != -1)
                maxPair = max(maxPair, p.second.first + p.second.second);
        return maxPair;
    }
};