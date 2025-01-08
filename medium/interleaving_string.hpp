#pragma once

#include "../imports.hpp"

#if 0

class Solution {
private:
    bool solver(const string& s1, const string& s2, const string& s3, const int i1, const int i2) {
        if ((i1 + i2) == s3.size()) {
            return true;
        }

        bool result = false;

        if (i1 < s1.size() && s1[i1] == s3[i1 + i2]) {
            result |= this->solver(s1, s2, s3, i1 + 1, i2);
        }

        if (i2 < s2.size() && s2[i2] == s3[i1 + i2]) {
            result |= this->solver(s1, s2, s3, i1, i2 + 1);
        }

        return result;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        return this->solver(s1, s2, s3, 0, 0);
    }
};

#elif 1


class Solution {
private:
    bool solver(const string& s1, const string& s2, const string& s3, vector<vector<int>>& dpCache, const int i1, const int i2) {
        if ((i1 + i2) == s3.size()) {
            return true;
        } else if (dpCache[i1][i2] != -1) {
            return dpCache[i1][i2];
        }

        bool result = false;

        if (i1 < s1.size() && s1[i1] == s3[i1 + i2]) {
            result |= this->solver(s1, s2, s3, dpCache, i1 + 1, i2);
        }

        if (!result && i2 < s2.size() && s2[i2] == s3[i1 + i2]) {
            result |= this->solver(s1, s2, s3, dpCache, i1, i2 + 1);
        }

        dpCache[i1][i2] = result;

        return result;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if ((s1.size() + s2.size()) != s3.size()) {
            return false;
        }
        vector<vector<int>> dpCache(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return this->solver(s1, s2, s3, dpCache, 0, 0);
    }
};

#endif