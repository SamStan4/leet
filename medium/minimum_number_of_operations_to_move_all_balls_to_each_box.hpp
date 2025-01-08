#pragma once

#include "../imports.hpp"

class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int n = boxes.size();
        vector<int> answer(n, 0);
        int opsL = 0, countL = 0, opsR = 0, countR = 0;
        for (int i = 0, j = boxes.size() - 1; i < boxes.size(); ++i, --j) {
            answer[i] += opsL;
            answer[j] += opsR;
            if (boxes[i] == '1') countL++;
            if (boxes[j] == '1') countR++;
            opsL += countL;
            opsR += countR;
        }
        return answer;
    }
};