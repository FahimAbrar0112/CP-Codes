#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        path += "/";
        stack<string> st;

        string current;

        for (char ch : path)
        {

            if (ch == '/')
            {
                if (current == "..")
                {
                    if (!st.empty())
                        st.pop();
                }
                else if (current != "" && current != ".")
                {
                    st.push(current);
                }
                current = "";
            }
            else
            {
                current += ch;
            }
        }

        string ans;
        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans == "" ? "/" : ans;
    }
};
