#pragma once

#include "../imports.hpp"

class Solution {
private:
    int getLastOccurence(const vector<int>& n, int t) {
        int l = 0, r = n.size() - 1, i = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (n[m] == t) {
                i = m;
                l = m + 1;
            } else if (n[m] < t) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return i;
    }
    int getFirstOccurence(const vector<int>& n, int t) {
        int l = 0, r = n.size() - 1, i = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (n[m] == t) {
                i = m;
                r = m - 1;
            } else if (n[m] < t) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return i;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {this->getFirstOccurence(nums, target), this->getLastOccurence(nums, target)};
    }
};