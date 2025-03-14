#include "../imports.hpp"

class Solution {
public:
    int maximumCandies(std::vector<int>& candies, long long k) {
        std::function<bool(int)> check = [&candies, k](int candy) -> bool {
            long long total = 0;
            for (int i = 0; i < (int)candies.size(); ++i) {
                total += candies[i] / candy;
            }
            return total >= k;
        };
        int l = 1, r = *std::max_element(candies.begin(), candies.end()), ans = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(m)) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};