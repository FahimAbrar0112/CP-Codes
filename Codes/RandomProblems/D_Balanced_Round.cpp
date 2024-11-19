#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;



int main(void)
{
    int t;
    cin >>t ;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int ct=0;
        for(int i=n-1;i>=0;i--)
        {
            if( (v[i]-v[i-1]) > k )
            {
                 ct=i;
                 break;

            }
             
        }
        cout<<ct<<endl;
    }
    


    return 0;
}