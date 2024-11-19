#include<bits/stdc++.h>
using namespace std;

const int N=1e7+10;
vector<bool>isPrime(N,1);
vector<int>hp(N,0),lp(N,0);

void sieve_highest_and_lowest_prime()
{   
    // O(n log log n)
    
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=N;i++)
    {
        if(isPrime[i])
        {
           lp[i]=hp[i]=i; 
            for(int j=2*i;j<=N;j+=i)
            {
                isPrime[j]=false;
                hp[j]=i;
                if(lp[j]==0)
                 lp[j]=i;
            }

        }
    }
}


int main(void)
{
    sieve_highest_and_lowest_prime();
    // for(int i=1;i<=100;i++)
    // {
    //     cout<<i<<" "<<isPrime[i]<<" "<<lp[i]<<" "<<hp[i]<<endl;
    // }
    
    int num;
    cin>>num;
    unordered_map<int,int>prime_factors;

    while(num>1)
    {
        int prime_factor=hp[num];

        while(num%prime_factor==0)
        {
            num/=prime_factor;
            prime_factors[prime_factor]++;
        }
    }

    for(auto val:prime_factors) 
    {
        cout<<val.first<<"  "<<val.second<<endl;
    }

    return 0;
}