#include "../imports.hpp"

class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
        int l = *std::max_element(weights.begin(), weights.end());
        int r = std::accumulate(weights.begin(), weights.end(), 0);
        std::function<bool(int)> isValid = [&weights, days](int weightCapacity) -> bool {
            int daysNeeded = 1, curWeight = 0;
            for (int i = 0; i < (int)weights.size(); ++i) {
                if (curWeight + weights[i] > weightCapacity) {
                    ++daysNeeded;
                    curWeight = 0;
                }
                curWeight += weights[i];
                if (daysNeeded > days) {
                    return false;
                }
            }
            return true;
        };
        while (l <= r) {
            int m = (l + r) / 2;
            if (isValid(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};