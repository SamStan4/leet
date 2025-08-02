#include "../imports.hpp"

#if 0

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1'000'000'007, arrSize = (int)arr.size();
        long long count = 0;
        for (int i = 0; i < arrSize; ++i) {
            int curCount = 0;
            for (int j = i; j < arrSize; ++j) {
                curCount += arr[j];
                if (curCount % 2 != 0) {
                    ++count;
                }
            }
        }
        return (int)(count % MOD);
    }
};

#else

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int arrSize = (int)arr.size();
        int count = 0, oddCount = 0, evenCount = 1, prefixSum = 0;
        for (int i = 0; i < arrSize; ++i) {
            prefixSum += arr[i];
            if (prefixSum % 2 == 0) {
                count += oddCount;
                ++evenCount; 
            } else {
                count += evenCount;
                ++oddCount;
            }
            count %= 1'000'000'007;
        }
        return count;
    }
};

#endif