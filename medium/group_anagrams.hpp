#pragma once

#include "./../imports.hpp"

class Solution
{
private:
    static bitset<200> get_string_encoding(string& s)
    {
        bitset<200> code = 0x0;
        unsigned short int freq[26] = { 0 };
        int s_size = s.size();

        for (int i = 0; i < s_size; ++i)
        {
            ++freq[s[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i)
        {
            bitset<7> temp(freq[i]);

            for (int j = 0; j < 7; ++j)
            {
                if (temp[j])
                {
                    code.set((i * 7) + j);
                }
            }
        }

        return code;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<bitset<200>, int> string_map;
        vector<vector<string>> anagrams;
        bitset<200> code;
        int strs_size = strs.size();


        for (int i = 0; i < strs_size; ++i)
        {
            code = this->get_string_encoding(strs[i]);

            if (string_map.find(code) == string_map.end())
            {
                string_map[code] = anagrams.size();

                anagrams.push_back({});
            }

            anagrams[string_map[code]].push_back(strs[i]);
        }

        return anagrams;
    }
};

static int _performance_boost_ = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 0;
} ();