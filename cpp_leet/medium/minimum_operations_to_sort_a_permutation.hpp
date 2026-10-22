#include <cmath>
#include <ios>
#include <iostream>
#include <vector>

class Solution {
public:
    int minOperations(
        const std::vector<int>& nums
    );
};

// NOLINTBEGIN(misc-definitions-in-headers)

int Solution::minOperations(
    const std::vector<int>& nums
) {
    const int n = static_cast<int>(nums.size());

    int incPivotIdx = -1;
    int decPivotIdx = -1;

    for (int i = 1, j = n - 2; i < n; ++i, --j) {

        if (nums[i] < nums[i - 1] && incPivotIdx != -2) {
            if (incPivotIdx != -1 || nums[0] < nums[n - 1]) {
                incPivotIdx = -2;
            } else {
                incPivotIdx = i;
            }
        }

        if (nums[j] < nums[j + 1] && decPivotIdx != -2) {
            if (decPivotIdx != -1 || nums[0] > nums[n - 1]) {
                decPivotIdx = -2;
            } else {
                decPivotIdx = i;
            }
        }

        if (incPivotIdx == -2 && decPivotIdx == -2) {
            return -1;
        }
    }

    // Sorted in increasing order, nothing needed
    if (incPivotIdx == -1) {
        return 0;
    }

    // Sorted in decreasing order, just need to reverse once
    if (decPivotIdx == -1) {
        return 1;
    }

    if (incPivotIdx != -2) {
        return std::min(incPivotIdx, 2 + n - incPivotIdx);
    }

    if (decPivotIdx != -2) {
        return std::min(decPivotIdx, n - decPivotIdx) + 1;
    }

    return -1;
}

static int init_func = []() -> int {
    std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

// NOLINTEND(misc-definitions-in-headers)


/*

[  ]

CASE ONE - sorted in ascending

[ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ]

CASE TWO - sorted in ascending, but shifted

[ 5, 6, 7, 8, 9, 0, 1, 2, 3, 4 ]
  0  1  2  3  4  5  6  7  8  9

min(i, n - i)

i = 5
n = 10

CASE THREE - sorted in descending

[ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 ]

CASE FOUR - sorted in descending, but shifted

[ 4, 3, 2, 1, 0, 9, 8, 7, 6, 5 ]
  0  1  2  3  4  5  6  7  8  9

min(i, n - i) + 1

CASE FIVE - not sortable

[ some random vector here ]


[ 2, 3, 4, 5, 6, 7, 8, 9, 0, 1 ] (REG)
  0  1  2  3  4  5  6  7  8  9
                          ^
                          i

Need i shifts

[ 1, 0, 9, 8, 7, 6, 5, 4, 3, 2 ] (REV)
  0  1  2  3  4  5  6  7  8  9
     ^
     i

4 = 2 + 10 - 8
need 2 + n - i shifts

*/