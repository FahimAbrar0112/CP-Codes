#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;



int main(void)
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        
        map<int,int> mp;
        for(int i=1;i<=n;i++)
        {
            int key,val;
            cin >>key>> val ;
            if(key<=10)
            {
                mp[val]=i;
            }
        }
        auto it=--mp.end();
        cout<<it->second<<endl;
    }
    


    return 0;
}