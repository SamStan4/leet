pragma once

#include "../imports.hpp"

class Solution {
private:
	bool isPrefix(const string& word, const string& prfx) {
		if (word.size() < prfx.size()) {
			return false;
		}
		for (int i = 0; i < prfx.size(); ++i) {
			if (word[i] != prfx[i]) {
				return false;
			}
		}
		return true;
	}
public:
	int prefixCount(vector<string>& words, string pref) {
        	int count = 0;
		for (int i = 0; i < words.size(); ++i) {
			count += this->isPrefix(words[i], pref) ? 1 : 0;
		}	
		return count;
	}
};
