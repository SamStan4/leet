#pragma once

#include "../imports.hpp"

class Solution {
private:
    int getNext(int cur)  {
        int next = 0;
        while (cur) {
            int digit = cur % 10;
            cur /= 10;
            next += digit * digit;
        }
        return next;
    }
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            fast = getNext(getNext(fast));
            slow = getNext(slow);
            if (fast == 1) {
                return true;
            } else if (slow == fast) {
                return false;
            }
        }
        return false;
    }
};