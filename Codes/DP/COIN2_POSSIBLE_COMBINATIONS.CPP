#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[N];

int func(int amount,vector<int>&coins)
{
    if(amount==0) return 1;
    if(dp[amount]!=-1) return dp[amount];

    int ways = 0;
    for(auto coin : coins)
    {
        if(amount-coin>=0)
         ways+=  func(amount-coin, coins) ;
         //cout<<ans<<endl;
    }

   return dp[amount] = ways;      
}

int coinChange(vector<int>&coins,int amount)
{   
    memset(dp,-1,sizeof(dp));
    int ways = func(amount,coins);
    return ways == INT_MAX?-1:ways;
}



int main(int argc,char * argv[])
{   
    vector<int> coins = {1,2,5};
    cout<<coinChange(coins,5);

    

    



    return 0;
}

/*  
     1 1 1 1 1 
     1 1 1 2
     1 1 2 1
     1 2 1 1
     2 1 1 1
     1 2 2
     2 1 1 1
     2 2 1
     5
     => TOTAL 9 poswsibilities 
     combinatorics problem:
     num of  all possible wways in which the amoun can be 0 using the coins 
     here order matters 

     the actual ans will be 
     1 1 1 1 1
     1 1 1 2
     1 2 2
     5
     => 4 
      if we dont take the orders seriously.
      


*/