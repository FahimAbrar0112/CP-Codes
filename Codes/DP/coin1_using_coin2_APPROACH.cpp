#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+10;
long long dp[310][N];

long long func(long long ind,long long amount,vector<long long>&coins)
{
    if(amount==0) 
    {
        return 0;
    } 
    if(ind<0)
    {
        return INT_MAX; 

    } 
    if(dp[ind][amount]!=-1) return dp[ind][amount];

    long long ways=INT_MAX;
    for(long long coin_amount=0;coin_amount<=amount;coin_amount+=coins[ind])
    {
        //cout<<coin_amount<<endl;
        long long hehe=coin_amount/coins[ind];
        if(amount-coin_amount>=0)
         ways = min( ways+0ll, func(ind-1,amount-coin_amount, coins)+hehe+0LL);

    }

   return dp[ind][amount]=ways;      
}
long long change(long long amount,vector<long long>&coins)
{   
    memset(dp,-1,sizeof(dp));
    return func(coins.size()-1,amount,coins);
}


int main( void )
{   
   vector<long long> coins = {1,2,5};
    cout<<change(15,coins);

    return 0;
}

/*  
    3 11
    1 2 5

*/