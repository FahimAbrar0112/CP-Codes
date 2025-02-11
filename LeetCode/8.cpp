#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    int myAtoi(string s)
    {

        int index = 0;
        int n = s.size();
        int sign = 1;
        long long ans = 0;

        while (index < n && s[index] == ' ')
        {
            index++;
        }

        if (s[index] == '-' || s[index] == '+')
        {
            if (s[index] == '-')
                sign = -1;

            index++;
        }

        while (index < n && s[index] == '0')
        {
            index++;
        }

        while (index < n && isDigit(s[index]))
        {
            ans = ans * 10 + s[index] - '0';
            index++;

            if (ans > INT_MAX)
                return sign==1 ? INT_MAX : INT_MIN;
        }

        ans *= sign;
 

        return ans;
    }
};
