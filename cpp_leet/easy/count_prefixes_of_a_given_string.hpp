#pragma once

#include "../imports.hpp"

int isPrefix(char* word, char* prfx) {
	int i = 0;
	for (; word[i] != '\0' && prfx[i] != '\0'; ++i) {
		if (word[i] != prfx[i]) {
			return 0;
		}
	}
	return prfx[i] == '\0';
}

int countPrefixes(char** words, int wordsSize, char* s) {
	int count = 0;
	for (int i = 0; i < wordsSize; ++i) {
		if (isPrefix(s, words[i])) {
			++count;
		}
	}
	return count;
}
