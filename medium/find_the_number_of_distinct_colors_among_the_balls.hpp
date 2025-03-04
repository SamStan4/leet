#pragma once

#include "./../imports.hpp"


class Solution {
public:
	vector<int> queryResults(int limit, vector<vector<int>>& queries) {
		const int queriesSize = (int)queries.size();
		unordered_map<int, unsigned int> colorCounts;
		unordered_map<int, int> ballColor;
		vector<int> answer(queriesSize);

		for (unsigned int i =  0; i < queriesSize; ++i) {
			const int ballNum = queries[i][0];
			const int colorNum = queries[i][1];

			if (ballColor.find(ballNum) != ballColor.end() && colorNum == ballColor[ballNum]) {
				answer[i] = colorCounts.size();
				continue;
			}

			if (ballColor.find(ballNum) != ballColor.end()) {
				--colorCounts[ballColor[ballNum]];
				if (colorCounts[ballColor[ballNum]] == 0) {
					colorCounts.erase(ballColor[ballNum]);
				}
			}

			ballColor[ballNum] = colorNum;
			++colorCounts[colorNum];

			answer[i] = colorCounts.size();
		}

		return answer;
	}
};

static int init = []() {
	ios_base::sync_with_stdio(false),
		cin.tie(nullptr),
		cout.tie(nullptr);
	return 0;
} ();