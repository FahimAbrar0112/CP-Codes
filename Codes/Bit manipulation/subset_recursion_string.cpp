#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;


vector<string> valied ;

void generate(string &s,vector<char>&v,int i)
{
    if(i==v.size()) 
    {
        valied.push_back(s);
        return;
    }

    
    s.push_back(v[i]);
    generate(s,v,i+1);
    s.pop_back();

    generate(s,v,i+1);
}


int main(void)
{
    int n;
    cin>>n;
    vector<char> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    string s;

    generate(s,v,0);

    for(auto val:valied)
    {
        cout<<val<<endl;
    }



    return 0;
}

/*

    3
    a b c

*/