#pragma once

#include "../imports.hpp"

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        ans.reserve(k);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        set<pair<int, int>> vis;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        vis.insert({0, 0});
        while (k-- && !pq.empty()) {
            const int s = pq.top().first, i1 = pq.top().second.first, i2 = pq.top().second.second;
            pq.pop();
            ans.push_back({nums1[i1], nums2[i2]});
            if (i1 + 1 < nums1.size() && vis.find({i1 + 1, i2}) == vis.end()) {
                vis.insert({i1 + 1, i2});
                pq.push({nums1[i1 + 1] + nums2[i2], {i1 + 1, i2}});
            }
            if (i2 + 1 < nums2.size() && vis.find({i1, i2 + 1}) == vis.end()) {
                vis.insert({i1, i2 + 1});
                pq.push({nums1[i1] + nums2[i2 + 1], {i1, i2 + 1}});
            }
        }
        return ans;
    }
};