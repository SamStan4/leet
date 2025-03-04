#include "../imports.hpp"

#if 0

char findTheDifference(char* s, char* t) {
    unsigned int freq[26] = { 0 };
    for (int i = 0; t[i] != '\0'; ++i) {
        ++freq[t[i]-'a'];
    }
    for (int i = 0; s[i] != '\0'; ++i) {
        --freq[s[i]-'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            return 'a' + i;
        }
    }
    return '\0';
}

#else

char findTheDifference(char* s, char* t) {
    char ans = '\0';
    while (*s != '\0') {
        ans ^= *s;
        ++s;
    }
    while (*t != '\0') {
        ans ^= *t;
        ++t;
    }
    return ans;
}

#endif