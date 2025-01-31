#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> charCount;

        // Count the frequency of each character in magazine
        for (char c : magazine)
        {
            charCount[c]++;
        }

        // Check if ransomNote can be constructed
        for (char c : ransomNote)
        {
            if (charCount[c] == 0)
                return false;
            charCount[c]--;
        }

        return true;
    }
};
