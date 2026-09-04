// NOLINTBEGIN(misc-definitions-in-headers)

# if 0

#include <vector>

class Solution {
public:
    int firstStableIndex(
        const std::vector<int>& nums,
        const int k
    ) {
        const int n = static_cast<int>(nums.size());

        std::vector<int> nums_min(n);
        std::vector<int> nums_max(n);

        nums_min[n - 1] = nums[n - 1];
        nums_max[0]     = nums[0];

        for (
            int i = 1, j = n - 2;
            i < n && j >= 0;
            ++i, --j
        ) {
            nums_min[j] = std::min(nums_min[j + 1], nums[j]);
            nums_max[i] = std::max(nums_max[i - 1], nums[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (nums_max[i] - nums_min[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};

#else

#include <vector>
#include <limits>

class Solution {
public:
    int firstStableIndex(
        const std::vector<int>& nums,
        const int k
    ) {
        const int n = static_cast<int>(nums.size());

        std::vector<int> nums_min(n);
        nums_min[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            nums_min[i] = std::min(nums_min[i + 1], nums[i]);
        }

        for (
            int i = 0, nums_max = std::numeric_limits<int>::min();
            i < n;
            ++i
        ) {
            nums_max = std::max(nums_max, nums[i]);
            if (nums_max - nums_min[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};

#endif

// NOLINTEND(misc-definitions-in-headers)