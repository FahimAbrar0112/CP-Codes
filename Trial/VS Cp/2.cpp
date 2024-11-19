#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*
    ((a^b) / c )%M

*/
void init_code(){ 
    
    //fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
}

long long binExp(long long a,long long b,long long m)
{
     
    long long result =1;
    while(b > 0)
    {
        if(b&1)
        {
            result = (result*1LL*a)%m;
        }
       a = (a*1LL*a)%m;
       b >>= 1;
    }
 
   return result%m;  
}



ll inv(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 
 

int main(void)
{
   init_code();
     long long a,b,c,m;
     cin>>a>>b>>c>>m;
     
     a%=m;

     long long numer = binExp(a,b,m)%m;
     long long denom = binExp(c,m-2,m)%m;
    
    cout<<numer<<" "<<denom<<endl;
    cout<<inv(c,m)<<endl;
    cout<< ((numer*1ll*denom)%m )<<endl;
     

    return 0;
}

/*

5 13 25 7

Output:  3

*/