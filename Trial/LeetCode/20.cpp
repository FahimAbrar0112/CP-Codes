#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        map<char,int>mp ={
             {'(',-1},
             {')',1},
             {'{',-2},
             {'}',2},
             {'[',-3},
             {']',3}
        };

      
        for(auto ch:s)
        {
             
            if(mp[ch]<0)
            st.push(ch);
            else
            {
                if(st.empty()) return 0;

                if(mp[ch]+mp[st.top()]==0)
                {
                    st.pop();
                }
                else
                {
                    return 0;
                }
            }
        }

        cout<<st.empty();
        if(st.empty()) return 1;

        return 0;

    }
};

int main(void)
{   
    



}