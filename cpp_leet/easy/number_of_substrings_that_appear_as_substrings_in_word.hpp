// NOLINTBEGIN(misc-definitions-in-headers)

#include <vector>
#include <string>

class Solution
{
public:
    int numOfStrings(
        const std::vector<std::string>& patterns,
        const std::string& word);
};

int Solution::numOfStrings(
    const std::vector<std::string>& patterns,
    const std::string& word)
{
    int answer = 0;

    for (const auto& pattern : patterns)
    {
        if (word.find(pattern) != std::string::npos)
        {
            ++answer;
        }
    }

    return answer;
}

// NOLINTEND(misc-definitions-in-headers)