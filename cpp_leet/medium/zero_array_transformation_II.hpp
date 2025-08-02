#include "../imports.hpp"

#if 0
// exceeds memory limit

class Solution {
public:
    int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        if (std::accumulate(nums.begin(), nums.end(), 0) == 0) {
            return 0;
        }
        std::vector<std::vector<int>> prefixSums(queries.size(), std::vector<int>(nums.size(), 0));
        for (int i = 0; i < queries.size(); ++i) {
            if (i > 0) {
                for (int j = 0; j < (int)prefixSums[i].size(); ++j) {
                    prefixSums[i][j] += prefixSums[i-1][j];
                }
            }
            for (int j = queries[i][0]; j <= queries[i][1]; ++j) {
                prefixSums[i][j] += queries[i][2];
            }
        }
        int l = 0, r = (int)queries.size() - 1, ans = (int)queries.size() + 1;
        std::function<bool(int)> check = [&nums, &prefixSums](int idx) -> bool {
            for (int i = 0; i < (int)nums.size(); ++i) {
                if (nums[i] > prefixSums[idx][i]) {
                    return false;
                }
            }
            return true;
        };
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans >= (int)queries.size() ? -1 : ans + 1;
    }
};

#elif 0
// exceeds time limit

class Solution {
public:
    int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        if (std::accumulate(nums.begin(), nums.end(), 0) == 0) {
            return 0;
        }
        int l = 0, r = (int)queries.size() - 1, ans = (int)queries.size() + 1;
        std::function<bool(int)> check = [&nums, &queries](int idx) -> bool {
            std::vector<int> prefixSum(nums.size(), 0);
            for (int i = 0; i <= idx; ++i) {
                for (int j = queries[i][0]; j <= queries[i][1]; ++j) {
                    prefixSum[j] += queries[i][2];
                }
            }
            for (int i = 0; i < (int)nums.size(); ++i) {
                if (nums[i] > prefixSum[i]) {
                    return false;
                }
            }
            return true;
        };
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans >= (int)queries.size() ? -1 : ans + 1;
    }
};

#else

class Solution {
public:
    int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {

    }
};


#endif