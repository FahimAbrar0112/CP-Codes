#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string hashFunc(string s)
    {

        vector<int> count(26, 0);

        for (char ch : s)
        {

            count[ch - 'a']++;
        }

        string key;
        for (int val : count)
        {
            key += to_string(val) + "###";
        }

        return key;
    }

    bool isAnagram(string s, string t)
    {

        return hashFunc(s) == hashFunc(t);
    }
};
