#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;

unordered_map<char,int> mp =
{
    {'(',-1},{'[', -2}, {'{',-3 }, {')', +1},{']',+2},{'}',3}
};


string isBalanced(string s)
{
    stack<char>st;
    for(char bracket: s)
    {
        if(mp[bracket] <0)
        {
            st.push(bracket);
        }
        else
        {
            if(st.empty()) return "NO";
            char top  = st.top();
            st.pop();
            if(mp[top]+mp[bracket] !=0)
            {
                return "NO";
            }
        }
    }
    if(st.empty())
     return "YES";
    else
     return "NO";

}


int main(void)
{
    string s;
    cin>>s;
 
    cout<<isBalanced(s)<<endl;

    return 0;
}

/*  


{[([({})])]

*/