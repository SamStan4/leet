// NOLINTBEGIN(misc-definitions-in-headers)

#include <iostream>
#include <ios>
#include <string>

class Solution
{
public:
    static int getLucky(
        const std::string& s,
        const int k);
};

int Solution::getLucky(
    const std::string& s,
    const int k)
{
    int number = 0;

    for (const char c : s)
    {
        int n = static_cast<int>(c - 'a') + 1;

        while (n > 0)
        {
            number += n % 10;
            n /= 10;
        }
    }

    for (int i = 1; i < k; ++i)
    {
        int newNumber = 0;

        while (number > 0)
        {
            newNumber += number % 10;
            number /= 10;
        }

        number = newNumber;
    }

    return number;
}

static int init = []() -> int
{
    std::ios_base::sync_with_stdio(false),
        std::cin.tie(nullptr),
        std::cout.tie(nullptr);
    return 0;
} ();

// NOLINTEND(misc-definitions-in-headers)