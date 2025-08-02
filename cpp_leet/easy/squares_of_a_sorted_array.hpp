#include "../imports.hpp"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            nums[i] = nums[i] * nums[i];
        }
        vector<int> ans(nums.size(), 0);
        int i = 0, j = (int)nums.size() - 1, k = (int)nums.size() - 1;
        while (i <= j) {
            ans[k--] = nums[i] > nums[j] ? nums[i++] : nums[j--];
        }
        return ans;
    }
};