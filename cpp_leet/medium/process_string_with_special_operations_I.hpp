// NOLINTBEGIN(misc-definitions-in-headers)

#include <string>
#include <algorithm>

class Solution {
public:
    std::string processStr(
        const std::string& s);
};

std::string Solution::processStr(
    const std::string& s)
{
    std::string answer;

    for (size_t i = 0; i < s.size(); ++i)
    {
        switch (s[i])
        {
            case '*':
                if (!answer.empty()) answer.pop_back();
            break;
            case '#':
                answer += answer;
            break;
            case '%':
                // Check if there are two '%' characters in a row
                if (i + 1 < s.size() && s[i + 1] == '%')
                {
                    ++i;
                }
                else
                {
                    std::reverse(answer.begin(), answer.end());
                }
            break;
            default:
                // Check if the addition is followed by a deletion
                if (i + 1 < s.size() && s[i + 1] == '*')
                {
                    ++i;
                }
                else
                {
                    answer.push_back(s[i]);
                }
            break;
        }
    }

    return answer;
}

// NOLINTEND(misc-definitions-in-headers)



