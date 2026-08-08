// NOLINTBEGIN(misc-definitions-in-headers)

#include <string>
#include <array>
#include <algorithm>

class Solution {
private:
    static int factorial(const int n);
    static bool isPossible(const std::string& s, const int k);
public:
    static std::string smallestPalindrome(std::string& s, const int k);
};

int Solution::factorial(const int n) {
    
    int answer = 1;

    for (int i = 1; i <= n; ++i) {
        answer *= i;
    }

    return answer;
}

bool Solution::isPossible(const std::string& s, const int k) {

    const int n = static_cast<int>(s.size());
    const int m = n / 2;

    std::array<int, 26> freq{};

    for (int i = 0; i < m; ++i) {
        ++freq[static_cast<int>(s[i] - 'a')];
    }

    int totalUnique = 0;

    for (const int b : freq) {
        if (b != 0) {
            ++totalUnique;
        }
    }

    long long numerator = factorial(m);
    long long denominator = 1;

    for (int count : freq) {
        denominator *= factorial(static_cast<long long>(count));
    }

    long long permutations = numerator / denominator;

    return permutations >= k;
}

std::string Solution::smallestPalindrome(std::string& s, const int k) {

    const int n = static_cast<int>(s.size());
    const int m = n / 2;

    if (!Solution::isPossible(s, k)) {
        return "";
    }

    std::sort(s.begin(), s.begin() + m);

    for (int i = 1; i < k; ++i) {
        std::next_permutation(s.begin(), s.begin() + m);
    }

    int i = 0;
    int j = n - 1;

    while (i < j) {
        s[j] = s[i];
        ++i;
        --j;
    }

    return s;
}

// NOLINTEND(misc-definitions-in-headers)