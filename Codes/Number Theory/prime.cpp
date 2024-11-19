#include<bits/stdc++.h>
using namespace std;

 bool isPrime(int n)
 {
    
    if(n==1)
     return 0;

    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }

   return true; 
 }


vector<int> divisors(int n)
 {

    // O( sq root N) 
    vector<int>prime_factors;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            prime_factors.push_back(i);
            n/=i;
        }
    }
    if(n>1)
     prime_factors.push_back(n);
   return prime_factors; 
 }

 vector<int> divisors2(int n)
 {

    // O(N) 
    vector<int>prime_factors;
    for(int i=2;i<=n;i++)
    {
        while(n%i==0)
        {
            prime_factors.push_back(i);
            n/=i;
        }
    }
   return prime_factors; 
 }



int main(void)
{
    
    // for(int i=1;i<=100;i++)
    // {
    //     cout<<i<<" "<<isPrime(i)<<endl;
    // }

    int n;
    cin>>n;
    vector<int> prime_factors = divisors(n);

    for(int val:prime_factors)
    {
        cout<<val<<endl;
    }

   /// cout<<isPrime(1e9+5)<<endl;
    return 0;
}