#include <array>

class Solution
{
public:
    int maxProduct(int n);
};

int Solution::maxProduct(int n)
{
    int max_digit_one = 0;
    int max_digit_two = 0;

    while (n > 0)
    {
        int cur_digit = n % 10;
        n /= 10;

        if (cur_digit > max_digit_one)
        {
            std::swap(cur_digit, max_digit_one);
        }

        if (cur_digit > max_digit_two)
        {
            max_digit_two = cur_digit;
        }
    }

    return max_digit_one * max_digit_two;
}