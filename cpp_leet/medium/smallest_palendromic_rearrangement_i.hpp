// NOLINTBEGIN(misc-definitions-in-headers)


#if 0

#include <string>
#include <algorithm>

// Time:  O(n * log(n))
// Space: O(1) or O(n) if you consider modifying input variables as taking space
//
//   This approach takes use of sorting the first floor(1/2) of the characters in the
// string. Then we mirror the structure of the string onto the other side of the string.

class Solution {
public:
    std::string smallestPalindrome(std::string& s);
};

std::string Solution::smallestPalindrome(std::string& s) {

    const int n = static_cast<int>(s.size());

    // Note to self here:
    //   We are choosing to take the floor of (n / 2) here since, if the string has an odd
    // length, we cannot move the middle character. It will be the only character in the
    // string that has an odd frequency.
    std::sort(s.begin(), s.begin() + (n / 2));

    int i = 0;
    int j = n - 1;

    while (i < j) {
        s[j] = s[i];
        ++i;
        --j;
    }

    return std::move(s);
}

#else

#include <string>
#include <array>

// Time:  O(n)
// Space: O(1) or O(n) if you consider modifying input variables as taking space
//
//   This approach takes use of a frequency sort. I.e. bucket sort.

class Solution {
public:
    std::string smallestPalindrome(std::string& s);
};

std::string Solution::smallestPalindrome(std::string& s) {

    const int n = static_cast<int>(s.size());
    const int m = n / 2;

    std::array<int, 26> freq{};

    for (int i = 0; i < m; ++i) {
        ++freq[static_cast<int>(s[i] - 'a')];
    }

    int i = 0;
    int j = n - 1;
    int k = 0;

    while (i < j) {
        while (freq[k] <= 0) {
            ++k;
        }
        s[i] = static_cast<char>(k) + 'a';
        s[j] = s[i];
        --freq[k];
        ++i;
        --j;
    }

    return std::move(s);
}

#endif

// NOLINTEND(misc-definitions-in-headers)