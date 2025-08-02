#pragma once

#include "../imports.hpp"

#if 1

class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dpCache(n + 1, 0);
        dpCache[0] = dpCache[1] = 1;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                dpCache[i] += dpCache[j-1] * dpCache[i-j];
        return dpCache.back();
    }
};

#elif 1

class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dpCache(n + 1, 0);
        dpCache[0] = dpCache[1] = 1;
        const std::function<int(const int)> func = [&](const int n) -> int {
            if (dpCache[n] == 0) {
                for (int i = 1; i <= n; ++i) {
                    dpCache[n] += func(i - 1) * func(n - i);
                }
            }
            return dpCache[n];
        };
        return func(n);
    }
};

#else

class Solution {
public:
    int numTrees(int n) {
        if (n == 1 || n == 0) {
            return 1;
        }
        int total = 0;
        for (int i = 1; i <= n; ++i) {
            total += numTrees(i - 1) * numTrees(n - i);
        }
        return total;
    }
};

#endif