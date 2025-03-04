#pragma once


#include "../imports.hpp"
#if 0

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int n = mat.size(), m = mat[0].size();
        unordered_map<int, pair<int, int>> numToRowCol;
        vector<int> rowCount(n, 0), colCount(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                numToRowCol[mat[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < arr.size(); ++i) {
            const int r = numToRowCol[arr[i]].first, c = numToRowCol[arr[i]].second;
            ++rowCount[r];
            ++colCount[c];
            if (rowCount[r] == m || colCount[c] == n) {
                return i;
            }
        }
        return -1;
    }
};

#else

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int R = mat.size(), C = mat[0].size();
        vector<pair<int, int>> numToLocation((R * C) + 1);
        vector<int> rowCount(R, 0), colCount(C, 0);
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                numToLocation[mat[r][c]] = {r, c};
            }
        }
        for (int i = 0; i < arr.size(); ++i) {
            const int r = numToLocation[arr[i]].first,
                      c = numToLocation[arr[i]].second;
            ++rowCount[r];
            ++colCount[c];
            if (rowCount[r] == C || colCount[c] == R) {
                return i;
            }
        }
        return -1;
    }
};

#endif