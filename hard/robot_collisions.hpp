#pragma once

#include "./../imports.hpp"

class Solution
{
public:

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions)
    {
        vector<pair<pair<int, int>, pair<int, char>>> robots, stack;
        vector<int> answer;
        int n = positions.size();

        for (int i = 0; i < n; ++i)
        {
            robots.push_back({{positions[i], i}, {healths[i], directions[i]}});
        }

        sort(robots.begin(), robots.end());

        for (int i = 0; i < n; ++i)
        {
            while (true)
            {
                if ((stack.empty()) || (stack.back().second.second == 'L') || (robots[i].second.second == 'R'))
                {
                    stack.push_back(robots[i]);
                    break;
                }
                else
                {
                    if (stack.back().second.first < robots[i].second.first)
                    {
                        --robots[i].second.first;
                        stack.pop_back();
                    }
                    else
                    {
                        if (stack.back().second.first == robots[i].second.first)
                        {
                            stack.pop_back();
                            break;
                        }
                        else
                        {
                            --stack.back().second.first;
                            break;
                        }
                    }
                }
            }
        }

        n = stack.size();

        for (int i = 0; i < n; ++i)
        {
            swap(stack[i].first.first, stack[i].first.second);
        }

        sort(stack.begin(), stack.end());

        for (int i = 0; i < n; ++i)
        {
            answer.push_back(stack[i].second.first);
        }

        return answer;
    }
};

auto init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();