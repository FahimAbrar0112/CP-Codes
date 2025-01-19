#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValied(char ch)
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')||(ch>='0'&&ch<='9');
    }

    bool isPalindrome(string s)
    {
        string rev;

        for (int i = 0; i < s.size(); i++)
        {
            if (isValied(s[i]))
                rev.push_back(tolower(s[i]));
        }

        s= rev;
        cout << rev << endl;

        reverse(rev.begin(), rev.end());

        cout << rev << endl;
        return s == rev;
    }
};

// Alternative:

class Solution
{
public:
    bool isValied(char ch)
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
    bool isPalindrome(string s)
    {
        int start=0,end=s.size()-1;

        while(start<=end)
        {
            if (!isValied(s[start]))
            {
                start++;
                continue;
            }

            if (!isValied(s[end]))
            {
                end--;
                continue;
            }

            if(tolower(s[start]) !=tolower(s[end]) )
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }
        return 1;
    }
};




int main(void)
{

    string s = "A man,  a plan , a canal: Panama";

    Solution S;

    cout<<S.isPalindrome(s)<<endl;
}