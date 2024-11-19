#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;



int main(void)
{   
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;

        vector<int> points,cost;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            points.push_back(x);
        }

        for(int i=0;i<n;i++)
        {
            cost.push_back( i+1+points[i] );
        }
        sort(cost.begin(),cost.end());

        int ct=0;
        int sum=0;

        for(int i=0;i<n;i++)
        {   
            sum+=cost[i];
            if(sum<=c)
            {
                ct++;
            }
            else
            {
                break;
            }
        }

        cout<<ct<<endl;

    }  
    

    



    return 0;
}