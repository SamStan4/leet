#pragma once

#include "./../imports.hpp"

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::vector<std::string> numStrings(nums.size());
        for (int i = 0; i < (int)nums.size(); ++i) {
            numStrings[i] = std::to_string(nums[i]);
        }
        std::sort(numStrings.begin(), numStrings.end(), [](const string& a, const string& b){
            return  (b + a) < (a + b);
        });
        std::string answer;
        for (int i = 0; i < (int)numStrings.size(); ++i) {
            answer += numStrings[i];
        }
        if (answer[0] == '0') {
            return "0";
        }
        return answer;
    }
};