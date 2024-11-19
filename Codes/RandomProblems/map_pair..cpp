#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;



int main(void)
{
    int n;
    cin>>n;

    map<int,multiset<string>> mp;

    for(int i=1;i<=n;i++)
    {
        string s;
        int x;
        cin>>s>>x;
        mp[-x].insert(s);
    }

    cout<<endl<<endl;
    for(auto &val:mp)
    {
        for(auto it=val.second.begin();it!=val.second.end();it++)
        {
            cout<< *it<<" "<< -val.first<<endl;
        }
    }



    // map<pair<int,string>,int> mp;
    // for(int i=1;i<=n;i++)
    // {
    //     string s;
    //     int x;
    //     cin>>s>>x;
    //     x=-x;

    //     mp[{x,s}]++;
    // }    

    // cout<<endl<<endl;
    // for(auto &val:mp)
    // {
    //     auto F=val.first;
    //     auto L=val.second;

    //     while(L)
    //     {
    //         L--;
    //         cout<<F.second<<" "<< -F.first<<endl;
        
    //     }

    // }

    return 0;
}

/*

6
ab 123
cd 456
ab 123
ac 321
cd 432
bc 321

*/