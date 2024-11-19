#include<bits/stdc++.h>
using namespace std;



bool valied(int mid,vector<int>&v,int c)
{
    int ct=1;
    int curr_pos=0;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]-v[curr_pos] >= mid )
        {
            curr_pos=i;
            ct++;
        }
    }
    //cout<<mid<<" ct"<<ct<<" >=" <<(ct>=c)<<endl;
    return ct>=c;

}

int main(void)
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,c;
        cin>>n>>c;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        int lo=1,hi=v[n-1],mid;
        while(hi-lo>1)
        {
            mid=(hi+lo)/2;
            if(valied(mid,v,c))
             lo=mid;
            else
             hi=mid-1; 
        }

     //cout<<lo <<" "<< hi<<endl;
       if(valied(hi,v,c)) 
        cout<<hi<<endl;
       else
        cout<<lo<<endl; 

    }
    


    return 0;
}