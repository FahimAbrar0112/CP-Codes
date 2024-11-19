#include<bits/stdc++.h>
using namespace std;


int main(void)
{
    long long n,m;
    cin>>n>>m;
    vector<long long>arr;
    long long sum=0;
    for(long long i=0; i<n; i++)
    {
        long long num;
        cin>>num;
        sum+=num;
        arr.push_back(sum);
    }
    while(m--)
    {
        long long ques;
        cin>>ques;
        long long ans;
        long long low=0;
        long long high=n-1;
        long long mid;

        //Binary search: 
        
        while(high-low>1)
        {
            mid=(high+low)/2;
            if(arr[mid]>=ques)
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }
       cout<<"h: "<<high<<" l: "<<low<<endl;
        if(arr[low]>=ques)
        {
            long long ans;
            if(low>0)
            {
                ans=ques-arr[low-1];
            }
            else
            {
                ans=ques;
            }
            cout<<low+1<<" "<<ans<<endl;
        }
        else
        {
            long long ans;
            if(high>0)
            {
                ans=ques-arr[high-1];
            }
            else
            {
                ans=ques;
            }
            cout<<high+1<<" "<<ans<<endl;

        }
    }


}