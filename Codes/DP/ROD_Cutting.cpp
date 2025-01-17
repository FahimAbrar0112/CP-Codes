#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int dp[N];

int RodCutting(int len,vector<int>&prices)
{
    if(len==0) return 0;
    if(dp[len]!=-1) return dp[len];

    int ans=0;
     
     for(int len_to_cut=1;len_to_cut<=prices.size();len_to_cut++)
     {  
        if(len-len_to_cut>=0)
         ans=max( ans, RodCutting(len-len_to_cut,prices)+prices[len_to_cut-1] );  
     } 
    return dp[len]=ans;
}

int cutRod(int price[], int n) 
{
    memset(dp,-1,sizeof(dp));
    vector<int> prices(price,price+n) ;

    int ans =RodCutting(n,prices);

    return ans;
}

int main(int argc,char * argv[])
{       
     
      int n;
      cin >> n;
    int arr[n];
      for(int i=0;i<n;i++)
      {
        //int x;
        cin >> arr[i];
      }

      cout<<cutRod(arr,n)<<endl;


    

    



    return 0;
}

/*

    8
    1 5 8 9 10 17 17 20 

    op 22

*/