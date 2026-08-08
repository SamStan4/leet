// NOLINTBEGIN(misc-definitions-in-headers)

// Bruit force brahhhhh

class Solution {
private:
    static int getDigitProduct(int n);
public:
    static int smallestNumber(int n, int t);
};

int Solution::getDigitProduct(int n) {
    int digitProduct = 1;
    while (n > 0) {
        int digit = n % 10;
        digitProduct *= digit;
        n /= 10;
    }
    return digitProduct;
}

int Solution::smallestNumber(int n, int t) {
    while (Solution::getDigitProduct(n) % t) ++n;
    return n;
}

// NOLINTEND(misc-definitions-in-headers)