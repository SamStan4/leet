#include "../imports.hpp"

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        const int n = (int)nums.size();
        std::vector<int> ans(n);
        int s = 0, l = n - 1;
        for (int i = 0, j = n - 1; i < n && j >= 0; ++i, --j) {
            if (nums[i] < pivot) {
                ans[s++] = nums[i];
            }
            if (nums[j] > pivot) {
                ans[l--] = nums[j];
            }
        }
        while (s <= l) {
            ans[s++] = pivot;
        }
        return ans;
    }
};