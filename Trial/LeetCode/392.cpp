#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {

        int ind_t = 0;
        int ct = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = ind_t; j < t.size(); j++)
            {
                if (s[i] == t[j])
                {
                    ct++;
                    ind_t = j + 1;
                    break;
                }
            }
        }
        return ct == s.size();
    }
};


int main(void)
{
}