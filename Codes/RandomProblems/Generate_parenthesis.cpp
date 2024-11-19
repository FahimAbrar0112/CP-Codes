#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;

vector<string>valid;

void generate(string &s , int open , int close)
{
    if(open==0 && close==0)
    {
        valid.push_back(s);
        //cout<<s<<endl;
        return;
    }

    if(open>0)
    {
        s.push_back('(');
        generate(s, open-1, close);
        s.pop_back();
    }
    if(close>0)
    {
        if(open<close)
        {
            s.push_back(')');
            generate(s, open, close-1);
            s.pop_back();
        }
    }

}

int main(void)
{
    int n;
    cin>>n;
    string s;

    //cout<<"we";
    generate(s,n,n);

    for(auto val:valid)
    {
        cout<<val<<endl;
    }

    //cout<<"qq";



    return 0;
}