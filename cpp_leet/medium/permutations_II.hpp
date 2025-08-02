#include "../imports.hpp"

#if 0

class Solution {
private:
    void helper(vector<int>& nums, int idx, vector<vector<int>>& answer) {
        if (idx == (int)nums.size()) {
            answer.push_back(nums);
            return;
        }
        unordered_set<int> seen;
        for (int i = idx; i < (int)nums.size(); ++i) {
            if (seen.find(nums[i]) != seen.end()) {
                continue;
            }
            seen.insert(nums[i]);
            std::swap(nums[idx], nums[i]);
            this->helper(nums, idx + 1, answer);
            std::swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> answer;
        std::sort(nums.begin(), nums.end());
        this->helper(nums, 0, answer);
        return answer;
    }
};

#elif 0

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> answer;
        std::sort(nums.begin(), nums.end());
        do {
            answer.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));
        return answer;
    }
};

#else

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        const int n = (int)nums.size();
        std::vector<std::vector<int>> answer;
        const std::function<void(const int)> helper = [&](const int i) -> void {
            if (i == n) {
                answer.push_back(nums);
                return;
            }
            int seen = 0;
            for (int j = i; j < n; ++j) {
                if (seen & (1 << (nums[j] + 10))) {
                    continue;
                }
                seen |= 1 << (nums[j] + 10);
                std::swap(nums[i], nums[j]);
                helper(i + 1);
                std::swap(nums[i], nums[j]);
            }
        };
        std::sort(nums.begin(), nums.end());
        helper(0);
        return answer;
    }
};

#endif