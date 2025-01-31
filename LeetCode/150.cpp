#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_set<string> operations = {"+", "-", "*", "/"};

public:
    bool isOperator(string token)
    {

        return operations.count(token);
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (string s : tokens)
        {

            if (isOperator(s))
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int val;
                if (s == "+")
                    val = b + a;
                if (s == "-")
                    val = b - a;
                if (s == "*")
                    val = b * a;
                if (s == "/")
                    val = b / a;

                st.push(val);
                // cout<<a<<b<<s<<val<<endl;
            }
            else
            {
                st.push(stoi(s));
            }
        }

        return st.empty() ? -1 : st.top();
    }
};

