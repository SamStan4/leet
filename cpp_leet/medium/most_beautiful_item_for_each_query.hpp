#pragma once

#include "./../imports.hpp"

class Solution {
private:
    int getOptimalItem(vector<vector<int>>& items, int budget) {
        int l = 0, r = items.size() - 1, m = 0, maxBeauty = 0;
        while (l <= r) {
            m = l + ((r - l) / 2);
            if (items[m][0] <= budget) {
                maxBeauty = max(maxBeauty, items[m][1]);
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return maxBeauty;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // sort the item array based on the cost of each item
        sort(items.begin(), items.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
        });
        // eliminate expensive items
        vector<vector<int>> cheapItems;
        for (int i = 0; i < items.size(); ++i) {
            if (cheapItems.empty()) {
                cheapItems.push_back(items[i]);
            } else if (cheapItems.back()[0] == items[i][0]) {
                if (cheapItems.back()[1] < items[i][1]) {
                    cheapItems.pop_back();
                    cheapItems.push_back(items[i]);
                }
            } else if (cheapItems.back()[1] < items[i][1]) {
                cheapItems.push_back(items[i]);
            }
        }
        // build the answer
        vector<int> answer(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            answer[i] = this->getOptimalItem(cheapItems, queries[i]);
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