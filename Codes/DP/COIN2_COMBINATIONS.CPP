#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int dp[310][N];

int func(int ind,int amount,vector<int>&coins)
{
    if(amount==0) return 1;
    if(ind<0) return 0;
    if(dp[ind][amount]!=-1) return dp[ind][amount];

    int ways=0;
    for(int coin_amount=0;coin_amount<=amount;coin_amount+=coins[ind])
    {
        if(amount-coin_amount>=0)
         ways+=func(ind-1,amount-coin_amount, coins);
    }

   return dp[ind][amount] = ways;      
}

int change(int amount,vector<int>&coins)
{   
    memset(dp,-1,sizeof(dp));
    return func(coins.size()-1,amount,coins);
}


int main(int argc,char * argv[])
{   
    vector<int> coins = {10};
    cout<<change(10,coins);

    return 0;
}

/*  
    3 11
    1 2 5

*/