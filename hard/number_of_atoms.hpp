#pragma once

#include "./../imports.hpp"


class Solution
{
private:

    void get_element(string& f, pair<string, int>& element, int& idx)
    {
        string element_count;

        // assume that at this point f[idx] = some upper case character

        element.first.clear();
        element.second = 1;

        // read in the capital letter

        element.first.push_back(f[idx]);

        // read all lower case characters
        for (++idx; (idx < f.size()) && (f[idx] > 96) && (f[idx] < 123); ++idx)
        {
            element.first.push_back(f[idx]);
        }

        // now read all digit characters
        for (; (idx < f.size()) && (f[idx] > 47) && (f[idx] < 58); ++idx)
        {
            element_count.push_back(f[idx]);
        }

        if (element_count != "")
        {
            element.second = stoi(element_count);
        }

        --idx;
    }

    void get_multiplier(string& f, int& multiplier, int& idx)
    {
        string number;

        multiplier = 1;

        if (f[idx] == ')')
        {
            ++idx;
        }

        for (; (idx < f.size()) && (f[idx] > 47) && (f[idx] < 58); ++idx)
        {
            number.push_back(f[idx]);
        }

        if (number != "")
        {
            multiplier = stoi(number);
        }

        --idx;
    }

public:
    string countOfAtoms(string formula)
    {
        int i = 0, j = 0, m = 0;
        unordered_map<string, int> atom_counts;
        vector<pair<string, int>> atom_stack;
        vector<int> parentiesis_stops;
        pair<string, int> element;
        string answer;

        for (i = 0; i < formula.size(); ++i)
        {
            if (formula[i] == '(')
            {
                parentiesis_stops.push_back(atom_stack.size()-1);
            }
            else if (formula[i] == ')')
            {
                this->get_multiplier(formula, m, i);

                for (j = atom_stack.size() - 1; j > parentiesis_stops.back(); --j)
                {
                    atom_stack[j].second *= m;
                }

                parentiesis_stops.pop_back();

                if (parentiesis_stops.empty())
                {
                    for (j = 0; j < atom_stack.size(); ++j)
                    {
                        if (atom_counts.find(atom_stack[j].first) == atom_counts.end())
                        {
                            atom_counts[atom_stack[j].first] = 0;
                        }

                        atom_counts[atom_stack[j].first] += atom_stack[j].second;
                    }

                    atom_stack.clear();
                }
            }
            else
            {
                this->get_element(formula, element, i);

                if (parentiesis_stops.empty())
                {
                    if (atom_counts.find(element.first) == atom_counts.end())
                    {
                        atom_counts[element.first] = 0;
                    }

                    atom_counts[element.first] += element.second;
                }
                else
                {
                    atom_stack.push_back(element);
                }
            }
        }

        for (auto it = atom_counts.begin(); it != atom_counts.end(); ++it)
        {
            atom_stack.push_back({it->first, it->second});
        }

        sort(atom_stack.begin(), atom_stack.end());

        for (i = 0; i < atom_stack.size(); ++i)
        {
            answer += atom_stack[i].first;

            if (atom_stack[i].second != 1)
            {
                answer += to_string(atom_stack[i].second);
            }
        }

        return answer;
    }
};











































class Solution
{
private:

    pair<string, int> get_element(string& formula, int& idx)
    {
        string element, element_count;
        int i = idx + 1, element_count_int = 1;

        element.push_back(formula[idx]);

        for (; (i < formula.size()) && (formula[i] >= 'a') && (formula[i] <= 'z'); ++i)
        {
            element.push_back(formula[i]);
        }

        for (; (i < formula.size()) && (formula[i] >= '0') && (formula[i] <= '9'); ++i)
        {
            element_count.push_back(formula[i]);
        }

        i = idx - 1;

        if (element_count != "")
        {
            element_count_int = stoi(element_count);
        }

        return {element, element_count_int};
    }

    int get_multiplier(string& formula, int& idx)
    {
        string number;
        int i = idx + 1;

        for (; (i < formula.size()) && (formula[i] >= '0') && (formula[i] <= '9'); ++i)
        {
            number.push_back(formula[i]);
        }

        idx = i - 1;

        return stoi(number);
    }

public:
    string countOfAtoms(string formula)
    {
        unordered_map<string, int> element_freq;
        vector<pair<string, int>> atom_stack;
        vector<int> parenthesis_locations;
        pair<string, int> element;
        string answer;
        int i = 0, j = 0, k = 0, multiplier = 0;

        for (i = 0; i < formula.size(); ++i)
        {
            if (formula[i] == '(')
            {
                parenthesis_locations.push_back(atom_stack.size());
            }
            else if (formula[i] == ')')
            {
                multiplier = this->get_multiplier(formula, i);

                for (j = atom_stack.size() - 1; j >= parenthesis_locations.back(); --j)
                {
                    atom_stack[j].second *= multiplier;
                }

                parenthesis_locations.pop_back();

                if (parenthesis_locations.empty())
                {
                    for (j = 0; j < atom_stack.size(); ++j)
                    {
                        if (element_freq.find(atom_stack[i].first) == element_freq.end())
                        {
                            element_freq[atom_stack[i].first] = 0;
                        }

                        element_freq[atom_stack[i].first] += atom_stack[i].second;
                    }

                    atom_stack.clear();
                }
            }
            else // formula[i] should be some uppercase letter 
            {
                element = this->get_element(formula, i);

                if (parenthesis_locations.empty()) // push directly to hash table
                {
                    element_freq[element.first] += element.second;
                }
                else // push to the atom stack
                {
                    atom_stack.push_back(element);
                }
            }
        }

        for (auto it = element_freq.begin(); it != element_freq.end(); ++it)
        {
            atom_stack.push_back({it->first, it->second});
        }

        sort(atom_stack.begin(), atom_stack.end());

        for (i = 0; i < atom_stack.size(); ++i)
        {
            answer += atom_stack[i].first;

            if (atom_stack[i].second > 1)
            {
                answer += to_string(atom_stack[i].second);
            }
        }        

        return answer;
    }
};