#include "../imports.hpp"

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& v1, const std::vector<int>& v2) {
            return v1[0] < v2[0];
        });
        int i = 0, j = 1;
        for (; j < (int)intervals.size(); ++j) {
            if (intervals[i][1] >= intervals[j][0]) {
                intervals[i][1] = std::max(intervals[j][1], intervals[i][1]);
            } else {
                ++i;
                intervals[i][0] = intervals[j][0];
                intervals[i][1] = intervals[j][1];
            }
        }
        intervals.resize(i + 1);
        return intervals;
    }
};