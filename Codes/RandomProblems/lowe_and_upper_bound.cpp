#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;

int lower_Bound(vector<int>&v,int x)
{
    int lo=0,hi=v.size()-1,mid;
    
    while(hi-lo>1)
    {
        mid = (hi+lo)/2;
        if(v[mid]<x)
        {
            lo = mid+1;
        }
        else
            hi=mid;
    }
    if(v[lo]>=x) return lo;
    if(v[hi]>=x) return hi;
    return -1;

    
}

int upper_Bound(vector<int>&v,int x)
{
    int lo=0,hi=v.size()-1,mid;
    
    while(hi-lo>1)
    {
        mid = (hi+lo)/2;
        if(v[mid]<=x)
        {
            lo = mid+1;
        }
        else
            hi=mid;
    }
    if(v[lo]>x) return lo;
    if(v[hi]>x) return hi;
    return -1;
    
    
}

int main(void)
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int x;
    cin>>x;
    int ind = upper_Bound(v,x);
    cout<<ind<<" "<<v[ind]<<endl;




    return 0;
}
/*
    5
     1 3 5 7 9
     4
*/