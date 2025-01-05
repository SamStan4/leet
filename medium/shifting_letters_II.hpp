#pragma once

#include "../imports.hpp"

#if 0
// bruit force approach
// way too slow of an algotithm

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for (int i = 0; i < shifts.size(); ++i) {
            for (int j = shifts[i][0]; j <= shifts[i][1]; ++j) {
                s[j] = (((((s[j]-'a')+(shifts[i][2]==0?-1:1))%26)+26)%26)+'a';
            }
        }
        return s;
    }
};

#elif 1
// solution using prefix sum

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shiftAcc(s.size() + 1, 0);
        for (int i = 0; i < shifts.size(); ++i) {
            int inc = shifts[i][2] ? 1 : -1;
            shiftAcc[shifts[i][0]] += inc;
            shiftAcc[shifts[i][1] + 1] -= inc;
        }
        for (int i = 1; i < shiftAcc.size(); ++i) {
            shiftAcc[i] += shiftAcc[i-1];
        }
        for (int i = 0; i < s.size(); ++i) {
            s[i] = (((((s[i]-'a')+shiftAcc[i])%26)+26)%26)+'a';
        }
        return s;
    }
};

#elif 1
// reduced for loop usage

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shiftAcc(s.size() + 1, 0);
        for (int i = 0; i < shifts.size(); ++i) {
            int inc = shifts[i][2] ? 1 : -1;
            shiftAcc[shifts[i][0]] += inc;
            shiftAcc[shifts[i][1] + 1] -= inc;
        }
        for (int i = 1; i < shiftAcc.size(); ++i) {
            shiftAcc[i] += shiftAcc[i-1];
            s[i-1] = (((((s[i-1]-'a')+shiftAcc[i-1])%26)+26)%26)+'a';
        }
        return s;
    }
};


#endif