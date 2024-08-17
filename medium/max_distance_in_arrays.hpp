#pragma once

#include "./../imports.hpp"

/*
    NOTES:

    this problem took me a while to understand due to the requirement that the elements 
    that make up the max distance must be on separate row indexes.

    HAVING SAID THAT....

        The key to this problem is that we are initializeing our min and max values to the first
        index in the array. Then we are starting our loop at 1 and then calculating the max distance
        before we update our global mins and maxes. By doing that in this order, we can ensure
        that we are never calculating temporary max distances that are on the same row index. This
        is the key to doing this problem in O(n).

        Overall pretty solid problem that was much harder than I had origionally expected.

*/

class Solution
{
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int global_min = arrays[0][0],
            global_max = arrays[0].back(),
            max_distance = 0;

        for (int i = 1; i < arrays.size(); ++i)
        {
            int local_min = arrays[i][0],
                local_max = arrays[i].back();

            max_distance = max(max_distance, max((local_max - global_min), (global_max - local_min)));

            global_max = max(global_max, local_max);
            global_min = min(global_min, local_min);
        }

        return max_distance;
    }
};

static int _performance_boost_ = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();