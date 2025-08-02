#pragma once

#include "../imports.hpp"

class Solution {
private:
    int solver(set<int>& travelDays, vector<int>& costs, vector<int>& dpCache, int day) {
        if (day > 365) {
            return 0;
        } else if (dpCache[day] != -1) {
            return dpCache[day];
        } else if (travelDays.find(day) != travelDays.end()) {
            int a = costs[0] + this->solver(travelDays, costs, dpCache, day + 1),
                b = costs[1] + this->solver(travelDays, costs, dpCache, day + 7),
                c = costs[2] + this->solver(travelDays, costs, dpCache, day + 30);
            dpCache[day] = min(min(a, b), c);
        } else {
            dpCache[day] = this->solver(travelDays, costs, dpCache, day + 1);
        }
        return dpCache[day];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        set<int> travelDays(days.begin(), days.end());
        vector<int> dpCache(366, -1);
        return this->solver(travelDays, costs, dpCache, 1);
    }
};