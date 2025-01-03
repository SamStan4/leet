#pragma once

#include "../imports.hpp"

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        vector<vector<int>> sums(2, vector<int>(words.size(), 0));
        for (int i = 0, sum = 0; i < words.size(); ++i) {
            if (vowels.count(words[i][0]) && vowels.count(words[i].back())) {
                ++sum;
                sums[1][i] = 1;
            }
            sums[0][i] = sum;
        }
        vector<int> answer(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            answer[i] = sums[0][queries[i][1]] - sums[0][queries[i][0]] + sums[1][queries[i][0]];
        }
        return answer;
    }
};

