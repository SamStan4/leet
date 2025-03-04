#include "../imports.hpp"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int wordsLength = (int)words.size();
        const int wordLength = (int)words[0].size();
        const int stringSize = (int)s.size();
        unordered_map<string, pair<int, int>> mp;
        function<void(void)> resetMp = [&mp](void) -> void {
            for (auto it = mp.begin(); it != mp.end(); ++it) {
                it->second.first = 0;
            }
        };
        for (int i = 0; i < wordsLength; ++i) {
            ++mp[words[i]].second;
        }
    }
};