#include "../imports.hpp"

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unsigned int occ[26] = { 0 };
        for (int i = 0; i < (int)s.size(); ++i) {
            occ[s[i]-'a'] = i;
        }
        int sumDiff = 0;
        for (int i = 0; i < (int)t.size(); ++i) {
            sumDiff += std::abs(i - (int)occ[t[i]-'a']);
        }
        return sumDiff;
    }
};