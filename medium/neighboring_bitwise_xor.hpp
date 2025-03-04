#pragma once

#include "../imports.hpp"

class Solution {
public:
	bool doesValidArrayExist(vector<int>& derived) {      
		const int n = derived.size();
		int xorSum = 0;
		for (int i = 0; i < n; ++i) {
			xorSum ^= derived[i];
		}	
		return !xorSum;
	}
};
