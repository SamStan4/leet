#pragma once

#include "../imports.hpp"

class Solution {
private:
    void s(int n, int k, vector<vector<int>>& answer, vector<int>& cur, int curNum) {
        if (cur.size() == k) {
            answer.push_back(cur);
            return;
        }

        for (int newNum = curNum + 1; newNum <= n; ++newNum) {
            cur.push_back(newNum);
            this->s(n, k, answer, cur, newNum);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {    
        vector<vector<int>> answer;
        vector<int> t;
        this->s(n, k, answer, t, 0);
        return answer;
    }
};

static int init = []() {
    ios_base::sync_with_stdio(false),
        cin.tie(nullptr),
        cout.tie(nullptr);
    return 0;
} ();