#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int wt[105],val[105];
long long dp[105][N];

long long func(int ind,int wt_left)
{    //Func(ind,0) bag e jayga nai
    if(wt_left == 0) return 0;
    //func(-1,amount) bag e jayga ase but element r nai
    if(ind<0) return 0;

    if(dp[ind][wt_left]!=-1) return dp[ind][wt_left];

    //Dont choose item at ind
    long long ans = func(ind-1,wt_left);

    //Choose item at ind
    if(wt_left -wt[ind]>=0)
     ans=max(ans+0ll,func(ind-1,wt_left-wt[ind]) +val[ind]+0ll);

    return dp[ind][wt_left]= ans;
}

int main(int argc,char * argv[])
{   
      memset(dp,-1,sizeof(dp));
      int n,w;
      cin>>n>>w;
      for(int i=0;i<n;i++)
      {
        cin>>wt[i]>>val[i] ;
      }
      cout<<func(n-1,w);
    

    



    return 0;
}
/*
    3 8
    3 30
    4 50
    5 60
    // 90
*/