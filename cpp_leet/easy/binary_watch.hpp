#include <string>
#include <bits/stdc++.h>

class Solution
{
private:
    static constexpr int minuteBitMask = 0b00000000'00111111;
    static constexpr int hourBitMask   = 0b00000011'11000000;

    static bool isValid(const int time)
    {
        const int minute = time & minuteBitMask;
        const int hour   = (time & hourBitMask) >> 6;

        return hour < 12 && minute < 60;
    }


    static std::string intToTimeStr(const int time)
    {
        const int minute = time & minuteBitMask;
        const int hour   = (time & hourBitMask) >> 6;

        std::string timeStr;

        timeStr += std::to_string(hour);

        timeStr += ':';

        if (minute < 10)
        {
            timeStr += '0';
        }

        timeStr += std::to_string(minute);

        return timeStr;
    }

public:
    static std::vector<std::string> readBinaryWatch(int turnedOn) noexcept
    {
        static constexpr int stopTime = 1 << 10;

        std::vector<std::string> answer;

        for (int i = 0; i < stopTime; ++i)
        {
            if (__builtin_popcount(i) == turnedOn && Solution::isValid(i))
            {
                answer.emplace_back(Solution::intToTimeStr(i));
            }
        }

        return answer;
    }
};