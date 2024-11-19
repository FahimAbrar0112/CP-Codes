#include<bits/stdc++.h>
using namespace std;


vector<int>v ;
int n,h;
bool valied(int mid)
{
    vector<int> p = v ;
    
    int ct=0;
    for(int i=0;i<p.size();i++)
    {
        if(p[i]%mid==0 && p[i]>=mid)
        {
            ct+=p[i]/mid;
        }
        else
        {
            if(p[i]<mid) 
             ct+=1;
            else
             ct+=p[i]/mid+1;
        }
    }
    //cout<<ct<<" m"<<mid<<" "<<(ct>=h)<<endl;
    return ct<=h;

}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        v.clear();
        cin >> n>>h;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());

        int lo=1,hi=v[n-1],mid;
        while(hi-lo>1)
        {
            mid=(hi+lo)/2;
            // if(!valied(mid))
            // {
            //     lo=mid+1;                
            // }
            // else
            //  hi=mid;
            if(valied(mid))
            {
                hi=mid;               
            }
            else
               lo=mid+1;
        }

        if(valied(lo))
         cout<<lo<<endl;
        else 
         cout<<hi<<endl;
 
 
   }
    


    return 0;
}