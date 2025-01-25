#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {

        unordered_map<char, char> mpS_t, mpT_s;

        for (int i = 0; i < s.size(); i++)
        {
            auto itS = mpS_t.find(s[i]);
            auto itT = mpT_s.find(t[i]);

            if (itS == mpS_t.end() && itT == mpT_s.end())
            {
                mpS_t[s[i]] = t[i];
                mpT_s[t[i]] = s[i];
            }
            else
            {
                if (itS != mpS_t.end() && itT != mpT_s.end())
                {
                    if (itS->second == itT->first)
                        continue;
                }

                return 0;
            }
        }

        return 1;
    }
};

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {

        unordered_map<char, char> mpS, mpT;

        for (int i = 0; i < s.size(); i++)
        {

            if ((mpS.count(s[i]) && mpS[s[i]] != t[i]) || (mpT.count(t[i]) && mpT[t[i]] != s[i]))
                return 0;

            mpS[s[i]] = t[i];
            mpT[t[i]] = s[i];
        }

        return 1;
    }
};
