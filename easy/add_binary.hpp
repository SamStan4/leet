#pragma once

#include "../imports.hpp"

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.size() < b.size()) {
            swap(a, b);
        }
        a.push_back('0');
        int i = 0;
        for (; i < b.size(); ++i) {
            
        }
    }
};