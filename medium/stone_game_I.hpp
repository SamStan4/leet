#pragma once

#include "./../imports.hpp"


/*

    NOTES:

        this problem can be solve by simply returning true no joke

    

*/

struct pair_hash
{
    template <class t1, class t2>
    std::size_t operator()(const std::pair<t1, t2>& p) const
    {
        auto h1 = std::hash<t1>{}(p.first);
        auto h2 = std::hash<t2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

class Solution
{
public:
    bool stoneGame(vector<int>& piles)
    {
        unordered_map<pair<int, int>, int, pair_hash> dp;


    }
};