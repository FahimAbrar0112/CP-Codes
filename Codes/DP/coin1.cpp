#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[N];

int func(int amount,vector<int>&coins)
{
    if(amount==0) return 0;
    if(dp[amount]!=-1) return dp[amount];

    int ans = INT_MAX;
    for(auto coin : coins)
    {
        if(amount-coin>=0)
         ans=min(ans+0ll,func(amount-coin,coins)+1LL) ;
         //cout<<ans<<endl;
    }

   return dp[amount] = ans;      
}

int coinChange(vector<int>&coins,int amount)
{   
    memset(dp,-1,sizeof(dp));
    int ans = func(amount,coins);
    return ans == INT_MAX?-1:ans;
}



int main(int argc,char * argv[])
{   
    vector<int> coins = {2,5,7};
    cout<<coinChange(coins,11);

    

    



    return 0;
}

/*  
    3 11
    1 2 5

*/