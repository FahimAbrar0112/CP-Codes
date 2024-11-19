
#include<bits/stdc++.h>
using namespace std;

string longest_substr(string str)
{
    if(str.size()<=1) return "";
    unordered_set<char>u_st;
    u_st.insert(str.begin(), str.end());
    for(int i = 0; i < str.size();i++)
    {
        char ch_low = tolower(str[i]);
        char ch_up = toupper(str[i]);
        if(u_st.find(ch_low) == u_st.end() || u_st.find(ch_up) == u_st.end())
        {
            string l = longest_substr(str.substr(0,i));
            string r = longest_substr(str.substr(i+1,str.length()));
            if(l.size()==r.size())
                return l;
            if(l.size()>r.size())
                return l;
            else return r;
        }
    }
    return str;
}

int main()
{
    string str;
    cin >> str;
    cout<<longest_substr(str)<<endl;
}