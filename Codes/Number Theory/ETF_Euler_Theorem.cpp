#include<bits/stdc++.h>
using namespace std;

 
//Super Power:
 
 long long  binExp(long long a,long long b,long long M)
 {
    long long ans=1;

     while(b)
     {
        if(b&1)
         ans = (ans*a)%M;
        b>>=1;
        a = (a*a)%M; 
     }

   return ans;  

 }


int main(void)
{
    /*
    
        50^(64^32) % M =?
        M is prime
        M = 1e9+7

    
    */  
    
    long long M = 1e9+7;
    cout<< binExp(50,binExp(64,32,M-1),M) <<endl;
    cout<<binExp(5,13,M)<<endl;


    return 0;
}