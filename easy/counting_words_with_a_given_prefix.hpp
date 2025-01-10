pragma once

#include "../imports.hpp"

#if 0

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

#else

int isPrefix(char* word, char* prfx) {
	int i = 0;
	for (; prfx[i] != '\0' && word[i] != '\0'; ++i) {
		if (word[i] != prfx[i]) {
			return 0;
		}
	}
	return prfx[i] == '\0';
}

int prefixCount(char** words, int wordsSize, char* pref) {
	int count = 0;
	for (int i = 0; i < wordsSize; ++i) {
		if (isPrefix(words[i], pref)) {
			++count;		
		}
	}
	return count;
}

#endif
