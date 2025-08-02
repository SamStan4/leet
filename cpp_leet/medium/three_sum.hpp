#pragma once

#include "./../imports.hpp"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
  	vector<vector<int>> answers;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i) {
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		int j = i + 1, k = nums.size() - 1;
		while (j < k) {
			int sum = nums[i] + nums[j] + nums[k];
			if (sum > 0) {
				--k;
			} else if (sum < 0) {
				++j;
			} else {
				answers.push_back({nums[i], nums[j], nums[k]});
				++j;
				while (j < k && nums[j] == nums[j - 1]) {
					++j;
				}
			}
		}
	}
	return answers;
    }
};

static int init = []() {
	ios_base::sync_with_stdio(false),
		cin.tie(nullptr),
		cout.tie(nullptr);
	return 0;
} ();
