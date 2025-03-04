#include "../imports.hpp"

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        const int n = (int)arr.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                const int resA = std::abs(arr[i] - arr[j]);
                if (resA > a) {
                    continue;
                }
                for (int k = j + 1; k < n; ++k) {
                    const int resB = std::abs(arr[j] - arr[k]);
                    if (resB > b) {
                        continue;
                    }
                    if (abs(arr[i] - arr[k]) <= c) {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};