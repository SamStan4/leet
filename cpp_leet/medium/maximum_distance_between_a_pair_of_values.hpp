#include <vector>

class Solution {
public:
    int maxDistance(std::vector<int>& nums1,
                    std::vector<int>& nums2) {
        
        const int n = static_cast<int>(nums1.size());
        const int m = static_cast<int>(nums2.size());
        int maxDist = 0;
        
        for (int i = 0, j = 0; i < n && j < m; ++i, ++j) {
            while (j + 1 < m && nums2[j + 1] >= nums1[i]) ++j;
            if (nums1[i] <= nums2[j]) {
                maxDist = std::max(maxDist, j - i);
            }
        }

        return maxDist;
    }
};