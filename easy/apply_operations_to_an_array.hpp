#include "../imports.hpp"

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        const int n = (int)nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i-1]) {
                nums[i-1] *= 2;
                nums[i] = 0;
            }
        }
        int i = 0, j = 0;
        for (; j < n; ++j) {
            if (nums[j] != 0) {
                nums[i++] = nums[j];
            }
        }
        for (; i < n; ++i) {
            nums[i] = 0;
        }
        return nums;
    }
};