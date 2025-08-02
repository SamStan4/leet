#pragma once

#include "./../imports.hpp"

class Solution
{
private:

    vector<pair<int, string>> number_strings = {
        {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"},
        {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"},
        {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"},
        {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"},
        {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"},
        {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"},
        {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"},
        {10, "Ten"}, {9, "Nine"}, {8, "Eight"},
        {7, "Seven"}, {6, "Six"}, {5, "Five"},
        {4, "Four"}, {3, "Three"}, {2, "Two"},
        {1, "One"}};

    string helper(int cur_number)
    {
        string number;

        for (int i = 0; i < this->number_strings.size(); ++i)
        {
            if (cur_number >= this->number_strings[i].first)
            {
                if (cur_number >= 100)
                {
                    number += this->helper(cur_number / this->number_strings[i].first) + " ";
                }

                number += this->number_strings[i].second;

                if ((cur_number % this->number_strings[i].first) != 0)
                {
                    number += " " + this->helper(cur_number % this->number_strings[i].first);
                }

                return number;
            }
        }

        return "";
    }

public:

    string numberToWords(int num)
    {
        if (num == 0) {
            return "Zero";
        }

        return this->helper(num);
    }
};