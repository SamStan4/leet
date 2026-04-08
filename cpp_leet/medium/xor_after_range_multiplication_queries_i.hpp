#include <vector>

class Solution
{
public:

    int xorAfterQueries(
        std::vector<int>& nums,
        const std::vector<std::vector<int>>& queries)
    {
        static const long long modulous = 1'000'000'007;

        for (const std::vector<int>& query : queries)
        {
            const int l = query[0];
            const int r = query[1];
            const int k = query[2];
            const int v = query[3];

            for (int i = l; i <= r; i += k)
            {
                nums[i] = static_cast<int>((static_cast<long long>(nums[i]) * static_cast<long long>(v)) % modulous);
            }
        }

        int answer = 0;

        for (const int num : nums)
        {
            answer ^= num;
        }

        return std::move(answer);
    }
};