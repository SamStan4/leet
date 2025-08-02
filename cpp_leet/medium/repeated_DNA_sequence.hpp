#pragma once

#include "./../imports.hpp"

// this works much much better

class Solution
{
private:

    int convert_string_to_code(string& s, int start_idx)
    {
        int code = 0x00000000;

        switch (s[start_idx])
        {
            case 'T':
                code |= 0b00000000000000000000000000000001;
            break;
            case 'G':
                code |= 0b00000000000000000000000000000010;
            break;
            case 'C':
                code |= 0b00000000000000000000000000000011;
            break;
        }
        switch (s[start_idx + 1])
        {
            case 'T':
                code |= 0b00000000000000000000000000000100;
            break;
            case 'G':
                code |= 0b00000000000000000000000000001000;
            break;
            case 'C':
                code |= 0b00000000000000000000000000001100;
            break;
        }
        switch (s[start_idx + 2])
        {
            case 'T':
                code |= 0b00000000000000000000000000010000;
            break;
            case 'G':
                code |= 0b00000000000000000000000000100000;
            break;
            case 'C':
                code |= 0b00000000000000000000000000110000;
            break;
        }
        switch (s[start_idx + 3])
        {
            case 'T':
                code |= 0b00000000000000000000000001000000;
            break;
            case 'G':
                code |= 0b00000000000000000000000010000000;
            break;
            case 'C':
                code |= 0b00000000000000000000000011000000;
            break;
        }
        switch (s[start_idx + 4])
        {
            case 'T':
                code |= 0b00000000000000000000000100000000;
            break;
            case 'G':
                code |= 0b00000000000000000000001000000000;
            break;
            case 'C':
                code |= 0b00000000000000000000001100000000;
            break;
        }
        switch (s[start_idx + 5])
        {
            case 'T':
                code |= 0b00000000000000000000010000000000;
            break;
            case 'G':
                code |= 0b00000000000000000000100000000000;
            break;
            case 'C':
                code |= 0b00000000000000000000110000000000;
            break;
        }
        switch (s[start_idx + 6])
        {
            case 'T':
                code |= 0b00000000000000000001000000000000;
            break;
            case 'G':
                code |= 0b00000000000000000010000000000000;
            break;
            case 'C':
                code |= 0b00000000000000000011000000000000;
            break;
        }
        switch (s[start_idx + 7])
        {
            case 'T':
                code |= 0b00000000000000000100000000000000;
            break;
            case 'G':
                code |= 0b00000000000000001000000000000000;
            break;
            case 'C':
                code |= 0b00000000000000001100000000000000;
            break;
        }
        switch (s[start_idx + 8])
        {
            case 'T':
                code |= 0b00000000000000010000000000000000;
            break;
            case 'G':
                code |= 0b00000000000000100000000000000000;
            break;
            case 'C':
                code |= 0b00000000000000110000000000000000;
            break;
        }
        switch (s[start_idx + 9])
        {
            case 'T':
                code |= 0b00000000000001000000000000000000;
            break;
            case 'G':
                code |= 0b00000000000010000000000000000000;
            break;
            case 'C':
                code |= 0b00000000000011000000000000000000;
            break;
        }

        return code;
    }

public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<int, int> str_freq;
        vector<string> repeated_strings;
        int stop = s.size() - 9, code = 0;

        for (int i = 0; i < stop; ++i)
        {
            code = this->convert_string_to_code(s, i);

            if (str_freq[code]++ == 1)
            {
                repeated_strings.push_back(s.substr(i, 10));
            }
        }

        return repeated_strings;
    }
};

static int _performance_boost_ = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr),
    cout.tie(nullptr);
    return 0;
} ();































// this works, it just kind of sucks

class Solution_bad
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> sub_string_freq;
        vector<string> repeated_sub_strings;
        string sub_string;
        int stop = s.size() - 9;

        for (int i = 0; i < stop; ++i)
        {
            sub_string = s.substr(i, 10);

            if (sub_string_freq[sub_string]++ == 1)
            {
                repeated_sub_strings.push_back(sub_string);
            }
        }

        return repeated_sub_strings;
    }
};

