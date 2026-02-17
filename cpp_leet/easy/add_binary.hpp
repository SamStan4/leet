#include <string>
#include <algorithm>

class Solution
{
public:
    std::string addBinary(const std::string& a, const std::string& b)
    {
        const int aSize = static_cast<int>(a.size());
        const int bSize = static_cast<int>(b.size());

        std::string answer; answer.reserve(std::max(a.size(), b.size()) + 1ul);

        int cIn{};

        for (int i{aSize - 1}, j{bSize - 1}; i >= 0 || j >= 0; --i, --j)
        {
            int sum{};

            sum += cIn;
            sum += i >= 0 ? static_cast<int>(a[i] == '1') : 0;
            sum += j >= 0 ? static_cast<int>(b[j] == '1') : 0;

            answer.push_back(sum % 2 == 1 ? '1' : '0');

            cIn = sum > 1 ? 1 : 0;
        }

        if (cIn != 0)
        {
            answer.push_back('1');
        }

        std::reverse(answer.begin(), answer.end());

        return answer;
    }
};