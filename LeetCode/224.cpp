#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    int calculate(string s)
    {
        stack<long long> st;

        long long sum = 0, sign = 1;

        for (int i = 0; i < s.size(); i++)
        {
            long long number = 0;

            if (isDigit(s[i]))
            {

                while (i < s.size() && isDigit(s[i]))
                {

                    number = number * 10 + s[i] - '0';
                    i++;
                }
                sum+=sign*number;
                i--;
            }
            else if( s[i]=='+')
             sign=1;
            else if(s[i]=='-')
             sign = -1;
            else if(s[i]=='(')
            {
                st.push(sum);
                st.push(sign);
                sum=0;
                sign=1;

            }  
            else if(s[i]==')')
            {
                sum  = st.top()*sum ;
                st.pop();
                sum = st.top()+sum;
                st.pop();

            }
        }
        return sum;
    }
};
