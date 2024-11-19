#include<bits/stdc++.h>
using namespace std;

//const int  M = 1e9+7;
const int  M = 1e6;
const int  N = 1e6;
int fact[N];

/*

There are N children and K toffees. K < N 17 // Count the number of ways to distribute toffee
 among N students such that each students get 19 1 toffee only --> nck
 N< 10 ^ 6, K < N < 10^ 6 , M=10^6
Q queries Q<10^5

n / ((n-r) ! * r !)

*/

int binExp(int a,int b,int m)
{
    int result =1;
    while (b > 0)
    {
        if(b&1)
        {
            result = (result*1LL*a)%m;
        }
       a = (a*1LL*a)%m;
       b >>= 1;
    }
    cout<<result<<endl;
   return result;  
}


/*

    B^-1 =>  binExp(B,M-2,M) ;

*/



int main(void)
{
     fact[0]=1;
     for(int i=1;i<N;i++)
     {
        fact[i]= (fact[i-1] *1LL* i)%M ; 
     }

     int q;
     cin>>q;
     while (q--)
     {
        int n,k;
        cin>>n>>k;
        //cout<<n<<k<<endl;

        int numerator = fact[n];
        int denom = (fact[n-k] * 1LL * fact[k])%M;
         denom = binExp(denom,M-2,M) % M;
        int ans = (numerator * denom)%M;   
        cout<<ans<<endl;
     
     }
     


    return 0;
}