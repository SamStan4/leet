#pragma once

#include "./../imports.hpp"

struct pair_hash
{
    template <class data_one, class data_two>
    size_t operator()(const pair<data_one, data_two> & pair) const 
    {
        return std::hash<data_one>{}(pair.first) ^ std::hash<data_two>{}(pair.second);
    }
};


class Solution
{
public:
    int maxPoints(vector<vector<int>>& points)
    {
        unordered_map<double, unordered_map<double, unordered_set<pair<int, int>, pair_hash>>> slope_y_intercept_point;
        unordered_map<double, unordered_set<pair<int, int>, pair_hash>> x_intercept_point;
        double numerator = 0, denominator = 0, slope = 0, intercept = 0;
        int max_points = 0;

        for (int i = 0; i < points.size(); ++i)
        {
            for (int j = i; j < points.size(); ++j)
            {
                numerator = points[j][1] - points[i][1]; // Y2 - Y1
                denominator = points[j][0] - points[i][0]; // X2 - X1

                if (denominator == 0)
                {
                    x_intercept_point[points[i][0]].insert({points[j][0], points[j][1]});
                    x_intercept_point[points[i][0]].insert({points[i][0], points[i][1]});
                }
                else
                {
                    slope = numerator / denominator; // (Y2 - Y1) / (X2 / X1)
                    intercept = points[j][1] - (slope * points[j][0]); // Y2 - mX2 = b

                    slope_y_intercept_point[slope][intercept].insert({points[j][0], points[j][1]});
                    slope_y_intercept_point[slope][intercept].insert({points[i][0], points[i][1]});
                }
            }
        }

        for (auto it1 = slope_y_intercept_point.begin(); it1 != slope_y_intercept_point.end(); ++it1)
        {
            for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2)
            {
                max_points = max(max_points, (int)it2->second.size());
            }
        }

        for (auto it = x_intercept_point.begin(); it != x_intercept_point.end(); ++it)
        {
            max_points = max(max_points, (int)it->second.size());
        }

        return max_points;
    }
};

auto init = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 'c';
} ();