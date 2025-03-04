#include "../imports.hpp"

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        const int n = (int)nums1.size(), m = (int)nums2.size();
        vector<vector<int>> ans;
        for (int i = 0, j = 0; i < n || j < m;) {
            if (i >= n) {
                ans.push_back(nums2[j++]);
            } else if (j >= m) {
                ans.push_back(nums1[i++]);
            } else {
                if (nums1[i][0] == nums2[j][0]) {
                    ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                    ++i;
                    ++j;
                } else if (nums1[i][0] < nums2[j][0]) {
                    ans.push_back(nums1[i++]);
                } else {
                    ans.push_back(nums2[j++]);
                }
            }
        }
        return ans;
    }
};