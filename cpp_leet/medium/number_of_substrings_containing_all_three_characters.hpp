// NOLINTBEGIN(misc-definitions-in-headers)

#include <iostream>
#include <ios>

#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int numberOfSubstrings(const std::string& s);
};

int Solution::numberOfSubstrings(const std::string& s)
{
    const int s_size = static_cast<int>(s.size());

    std::vector<int> a_indexes;
    std::vector<int> b_indexes;
    std::vector<int> c_indexes;

    a_indexes.reserve(s_size);
    b_indexes.reserve(s_size);
    c_indexes.reserve(s_size);

    for (int s_idx = 0; s_idx < s_size; ++s_idx)
    {
        switch (s[s_idx])
        {
            case 'a':
                a_indexes.push_back(s_idx);
            break;
            case 'b':
                b_indexes.push_back(s_idx);
            break;
            case 'c':
                c_indexes.push_back(s_idx);
            break;
        }
    }

    int answer = 0;

    const int a_indexes_size = static_cast<int>(a_indexes.size());
    const int b_indexes_size = static_cast<int>(b_indexes.size());
    const int c_indexes_size = static_cast<int>(c_indexes.size());

    int s_index = 0;
    int a_indexes_index = 0;
    int b_indexes_index = 0;
    int c_indexes_index = 0;

    while
    (
        s_index < s_size                 &&
        a_indexes_index < a_indexes_size &&
        b_indexes_index < b_indexes_size &&
        c_indexes_index < c_indexes_size
    )
    {
        int max_index = std::max
        (
            {
                a_indexes[a_indexes_index],
                b_indexes[b_indexes_index],
                c_indexes[c_indexes_index]
            }
        );

        answer += s_size - max_index;

        ++s_index;

        if      (s_index > a_indexes[a_indexes_index]) ++a_indexes_index;
        else if (s_index > b_indexes[b_indexes_index]) ++b_indexes_index;
        else if (s_index > c_indexes[c_indexes_index]) ++c_indexes_index;
    }

    return answer;
}

static int init = []() -> int
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

// NOLINTEND(misc-definitions-in-headers)