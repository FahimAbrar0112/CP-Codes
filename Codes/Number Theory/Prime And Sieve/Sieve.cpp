#include<bits/stdc++.h>
using namespace std;

const int N=1e7+10;
vector<bool>isPrime(N,1);

void sieve()
{   
    // O(n log log n)
    
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=N;i++)
    {
        if(isPrime[i])
        {
            for(int j=2*i;j<=N;j+=i)
            {
                isPrime[j]=false;
            }

        }
    }
}


int main(void)
{
    sieve();
    for(int i=1;i<=100;i++)
    {
        cout<<i<<" "<<isPrime[i]<<endl;
    }

    int ct=0;
    for(int i=1;i<N;i++)
    {
        if(isPrime[i])
        {
            ct++;
        }
    }

    cout<<ct<<endl;
    


    return 0;
}