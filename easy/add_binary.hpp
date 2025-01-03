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
        char cIn = '0';
        for (int i = 0; i < b.size(); ++i) {
            if (a[i] == '1' && b[i] == '1') {
                if (cIn == '0') {
                    a[i] = '0';
                }
            } else if (a[i] == '1' || b[i] == '1') {
                if (cIn == '1') {
                    a[i] = '0';
                } else {
                    a[i] = '1';
                }
            } else if 
        }
    }
};