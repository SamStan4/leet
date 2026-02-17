class Solution
{
public:
    int reverseBits(int n)
    {
        int answer = 0;

        for (int i = 0; i < 32; ++i, n >>= 1)
        {
            answer <<= 1;
            answer |= n & 1;
        }

        return answer;
    }
};