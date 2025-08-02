#pragma once

#include "./../imports.hpp"

class Solution
{
public:
    int minimumPushes(string word)
    {
        int letter_count[26] = {0}, total = 0;

        for (int i = 0; i < word.size(); ++i)
        {
            ++letter_count[word[i] - 97];
        }

        sort(begin(letter_count), end(letter_count), std::greater<>());

        for (int i = 0; i < 26; ++i)
        {
            total += ((i + 8) / 8) * letter_count[i];
        }

        return total;
    }
};

char init = []()
{
    ios_base::sync_with_stdio(0),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();