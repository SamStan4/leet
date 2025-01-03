#pragma once

#include "./../imports.hpp"

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q(gifts.begin(), gifts.end());
        while (k--) {
            q.push((int)sqrt(q.top()));
            q.pop();
        }
        long long answer = 0;
        while (!q.empty()) {
            answer += q.top();
            q.pop();
        }
        return answer;
    }
};