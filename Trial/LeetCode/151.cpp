#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> v;
        string tmp;
        vector<string> strs;
        bool flag = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                flag = 1;
                tmp.push_back(s[i]);
            }
            else
            {
                if (flag)
                {
                    flag=0;
                    strs.push_back(tmp);
                    tmp.clear();
                }
            }
        }
        if (tmp.size()!=0)
            strs.push_back(tmp);

        reverse(strs.begin(), strs.end());

        string ans;
        for (auto val : strs)
        {
            ans += val + " ";
        }

        ans.erase(ans.size() - 1);
        return ans;
    }
};

int main(void)
{
}