#pragma once

#include "../imports.hpp"

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freqOne[26] = { 0 },
            freqTwo[26] = { 0 };
        for (int i = 0; i < words2.size(); ++i) {
            for (int j = 0; j < words2[i].size(); ++j) {
                ++freqTwo[words2[i][j]-'a'];
            }
            for (int j = 0; j < 26; ++j) {
                freqOne[j] = max(freqOne[j], freqTwo[j]);
                freqTwo[j] = 0;
            }
        }
        vector<string> answer;
        for (int i = 0; i < words1.size(); ++i) {
            bool isGoodFlag = true;
            for (int j = 0; j < words1[i].size(); ++j) {
                ++freqTwo[words1[i][j]-'a'];
            }
            for (int j = 0; j < 26; ++j) {
                if (freqTwo[j] < freqOne[j]) {
                    isGoodFlag = false;
                }
                freqTwo[j] = 0;
            }
            if (isGoodFlag) {
                answer.push_back(words1[i]);
            }
        }
        return answer;
    }
};