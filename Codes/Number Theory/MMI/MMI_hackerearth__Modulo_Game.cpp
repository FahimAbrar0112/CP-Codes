#include<bits/stdc++.h>
using namespace std;
/*
    ((a^b) / c )%M

*/


long long binExp(long long a,long long b,long long m)
{
     
    long long result =1;
    while(b > 0)
    {
        if(b&1)
        {
            result = (result*1LL*a)%m;
            //cout<<result<<" ";
        }
       a = (a*1LL*a)%m;
       b >>= 1;
    }
    //cout<<endl<<result<<endl;
   return result;  
}



 

int main(void)
{
     long long a,b,c,m;
     cin>>a>>b>>c>>m;
     
     a%=m;

     long long numer = (binExp(a,b,m))%m;
     long long denom = (binExp(c,m-2,m))%m;
     // cout<<numer<<" "<<denom<<endl;
     
    cout<<((numer*1ll*denom)%m )<<endl;
 
     //cout<<ans<<endl;
 
    //cout<<binExp(17,5,7)<<endl;
     

     //cout<<((binExp(a,b,m)%m)*1LL*(binExp(c,m-2,m)%m))%m  <<endl;
    

    return 0;
}

/*

5 13 125 91


*/