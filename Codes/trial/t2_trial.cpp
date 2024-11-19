#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;



int main(void)
{
    int n,m;
    cin>>n>>m;


    vector<long long> v;

    long long sum=0;
    for(int i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        sum+=x;
        v.push_back(sum);

    }

    while(m--)
    {    
        
        long long query ;
        cin>>query;
         

        long long lo=0,hi=v.size()-1;
        

        while(hi-lo>1)
        {   
            
            long long mid = (hi+lo)/2;
            if(v[mid]<query) 
            {
                lo=mid+1;
            }
            else
            {
                hi=mid;
            }
            
        }

        
        if(query<=v[lo])
        {
            if(lo==0)
            {
                cout<<lo+1<<" "<<query<<endl;
            }
            else
            {
                cout<<lo+1<<" "<<query-v[lo-1]<<endl;
            }
        }
        else if(query<=v[hi])
        {
            cout<<hi+1<<" "<<query-v[hi-1]<<endl;

        }
    }


    return 0;
}