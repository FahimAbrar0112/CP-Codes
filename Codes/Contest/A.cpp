#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;



int main(void)
{
    map<int,int>mp;
    mp[11]=123;
    mp[1]=2;
    mp[4]=1234;

    for(auto x:mp)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }


    return 0;
}