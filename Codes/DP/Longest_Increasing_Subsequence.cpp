#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int nums[N];
int dp[N];

int lis(int i)  //O(N^2)
{
    if(dp[i]!=-1) return dp[i];
    
    int ans=1;
    

    for(int j=0;j<i;j++)
    {
        if(nums[j]<nums[i])
        {
            ans = max(ans,lis(j)+1) ;
        }
    }

    return dp[i]=ans;
}


int main(int argc,char * argv[])
{   
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }

    int ans=1;

    for(int i=0;i<n;i++)
    {
        ans=max(ans,lis(i) );
    }

    cout<<ans;


      

    



    return 0;
}

/*  
    8
    10 9 2 5 3 7 101 18


*/