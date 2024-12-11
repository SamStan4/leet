#pragma once

#include "./../imports.hpp"

class Solution {
private:
    bool solver(string& s, int idx, string& curWord, unordered_set<string>& wordSet) {
        if (idx == s.size()) {
            return curWord == "";
        }

        curWord.push_back(s[idx]);

        if (wordSet.find(curWord) != wordSet.end()) {
            string temp = "";
            if (this->solver(s, idx + 1, temp, wordSet)) {
                return true;
            }
        }

        return this->solver(s, idx + 1, curWord, wordSet);
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        string word = "";
        return this->solver(s, 0, word, wordSet);
    }
};