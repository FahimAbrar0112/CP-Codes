#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> valied;
    unordered_map<char, vector<char>> keys = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}};

    void generate(string &sub, int index, string &digits)
    {
        if (sub.size() == digits.size())
        {
            valied.push_back(sub);
            return;
        }

        if (index == digits.size())
        {

            return;
        }

        char ch = digits[index];
        for (char c : keys[ch])
        {

            sub.push_back(c);
            generate(sub, index + 1, digits);
            sub.pop_back();
        }

        generate(sub, index + 1, digits);
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        string sub;
        generate(sub, 0, digits);
        return valied;
    }
};
