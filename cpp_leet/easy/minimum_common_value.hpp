#include <vector>

class Solution {
public:
    int getCommon(std::vector<int>& nums_one, std::vector<int>& nums_two) {
        const int n = static_cast<int>(nums_one.size());
        const int m = static_cast<int>(nums_two.size());
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (nums_one[i] > nums_two[j]) {
                ++j;
            } else if (nums_one[i] < nums_two[j]) {
                ++i;
            } else {
                return nums_one[i];
            }
        }
        return -1;
    }
};