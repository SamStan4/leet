#include "../imports.hpp"

class Solution {
private:
    int bs(const vector<int>& n, int tar) {
        int l = 0, r = (int)n.size() - 1, res = (int)n.size();
        while (l <= r) {
            int m = (l + r) / 2;
            if (n[m] < tar) {
                l = m + 1;
            } else {
                res = m;
                r = m - 1;
            }
        }
        return res;
    }
public:
    int maximumCount(vector<int>& nums) {
        int neg = this->bs(nums, 0);
        int pos = (int)nums.size() - this->bs(nums, 1);
        return std::max(neg, pos);
    }
};