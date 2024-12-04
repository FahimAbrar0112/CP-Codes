#include <bits/stdc++.h>
using namespace std;

string isBalanced(string s)
{

    unordered_map<char, int> symbols = {
        {'(', 1},
        {')', -1},
        {'{', 2},
        {'}', -2},
        {'[', 3},
        {']', -3}

    };
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (symbols[s[i]] > 0)
            st.push(s[i]);
        else
        {
            if (st.empty())
                return "NO";
            else
            {
                if (symbols[s[i]] + symbols[st.top()] == 0)
                {
                    st.pop();
                    //  cout << "g";
                }
                else
                {
                    return "NO";
                }
            }
        }
    }

    if (st.empty())
        return "YES";
    else
        return "NO";
}

int main(void)
{

    int n;
    cin >>n;

    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }
}