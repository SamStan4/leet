#pragma once

#include "./../imports.hpp"

#define ONE_BILLION_AND_SEVEN 1000000007

#if 0

// bad solution without dynamic programming
// does not run fast enough

class Solution
{
private:
    int solver(vector<string>& words, string& target, int wordsIdx, int targetIdx)
    {
        if (targetIdx == target.size())
        {
            return 1;
        }

        long long count = 0; 

        for (int i = 0; i < words.size(); ++i)
        {
            if (words[i][wordsIdx] == target[targetIdx])
            {
                count += this->solver(words, target, wordsIdx + 1, targetIdx + 1);
            }
        }

        if (wordsIdx < words[0].size())
        {
            count += this->solver(words, target, wordsIdx + 1, targetIdx);
        }

        return count % ONE_BILLION_AND_SEVEN;
    }
public:
    int numWays(vector<string>& words, string target) {
        return this->solver(words, target, 0, 0);
    }
};

#elif 0

// better solution with dp cache
// still does not run fast enough

class Solution
{
private:
    int solver(vector<string>& words, string& target, vector<vector<int>>& dpCache, int wordsIdx, int targetIdx)
    {
        if (targetIdx == target.size())
        {
            return 1;
        }
        else if (wordsIdx >= words[0].size())
        {
            return 0;
        }
        else if (dpCache[wordsIdx][targetIdx] != -1)
        {
            return dpCache[wordsIdx][targetIdx];
        }

        long long count = 0;

        for (int i = 0; i < words.size(); ++i)
        {
            if (words[i][wordsIdx] == target[targetIdx])
            {
                count += this->solver(words, target, dpCache, wordsIdx + 1, targetIdx + 1);
            }
        }

        if (wordsIdx < words[0].size())
        {
            count += this->solver(words, target, dpCache, wordsIdx + 1, targetIdx);
        }

        count %= ONE_BILLION_AND_SEVEN;

        dpCache[wordsIdx][targetIdx] = count;

        return count;
    }

public:
    int numWays(vector<string>& words, string target)
    {
        vector<vector<int>> dpCache(words[0].size(), vector<int>(target.size(), -1));
        return this->solver(words, target, dpCache, 0, 0);
    }
};

#elif 1

static const int one_billion_and_seven = 1000000007;

class Solution
{
private:
    int solver(vector<string>& words, string& target, vector<vector<int>>& dpCache, vector<vector<int>>& charIdxFreq, int wordIdx, int targetIdx)
    {
        if (targetIdx == target.size())
        {
            return 1;
        }
        else if (wordIdx >= words[0].size())
        {
            return 0;
        }
        else if (dpCache[wordIdx][targetIdx] != -1)
        {
            return dpCache[wordIdx][targetIdx];
        }

        long long count = 0;

        count += this->solver(words, target, dpCache, charIdxFreq, wordIdx + 1, targetIdx);

        if (charIdxFreq[target[targetIdx] - 'a'][wordIdx] > 0)
        {
            count += (long long)this->solver(words, target, dpCache, charIdxFreq, wordIdx + 1, targetIdx + 1) * (long long)charIdxFreq[target[targetIdx] - 'a'][wordIdx];
        }

        count %= one_billion_and_seven;

        dpCache[wordIdx][targetIdx] = count;

        return count;
    }

public:
    int numWays(vector<string>& words, string target)
    {
        vector<vector<int>>
            dpCache(words[0].size(), vector<int>(target.size(), -1)),
            charIdxFreq(26, vector<int>(words[0].size(), 0));

        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j < words[i].size(); ++j)
            {
                ++charIdxFreq[words[i][j] - 'a'][j];
            }
        }

        return this->solver(words, target, dpCache, charIdxFreq, 0, 0);
    }
};

static int init = []()
{
    ios_base::sync_with_stdio(false),
        cin.tie(nullptr),
        cout.tie(nullptr);
    
    return 0;
} ();

#endif