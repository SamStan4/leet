// NOLINTBEGIN(misc-definitions-in-headers)

#if 0

#include <vector>
#include <unordered_set>

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int missingMultiple(
        const std::vector<int>& nums,
        const int k
    );
};

int Solution::missingMultiple(
    const std::vector<int>& nums,
    const int k
) {
    std::unordered_set<int> numSet;

    for (const int num : nums) {
        if (num % k == 0) {
            numSet.insert(num);
        }
    }

    int answer = k;

    for (; numSet.find(answer) != numSet.end(); answer += k);

    return answer;
}

#elif 0

#include <vector>
#include <algorithm>

// Time complexity: O(n * log(n))
// Space complexity: O(log(n))

class Solution {
public:
    int missingMultiple(
        std::vector<int>& nums,
        const int k
    );
};

int Solution::missingMultiple(
    std::vector<int>& nums,
    const int k
) {
    std::sort(nums.begin(), nums.end());

    int answer = k;

    for (const int num : nums) {
        if (num == answer) {
            answer += k;
        } else if (num > answer) {
            break;
        }
    }

    return answer;
}

#else

#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(1)

class Solution {
public:
    int missingMultiple(
        const std::vector<int>& nums,
        const int k
    );
};

int Solution::missingMultiple(
    const std::vector<int>& nums,
    const int k
) {

    int answer = k;

    for (; ; answer += k) {
        bool found = false;
        for (const int num : nums) {
            if (num == answer) {
                found = true;
                break;
            }
        }
        if (!found) {
            break;
        }
    }

    return answer;
}

#endif

// NOLINTEND(misc-definitions-in-headers)