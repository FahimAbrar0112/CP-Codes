#include<bits/stdc++.h>
using namespace std;

const int N=2e5+7; 
int multiples_ct[N];
int hsh[N];

int main(void)
{
    int n;
    cin>>n;
     
    for(int i=1;i<=n;i++)
    {   
        int val;
        cin>>val;
        hsh[val]++;
         
    }

    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            multiples_ct[i]+=hsh[j];

        }
    }

    int q;
    cin>>q;   
    //cout<<endl<<endl; 
    while (q--)
    {   
         
        int x,y;
        cin>>x>>y;
 
         long long ans = ( x*1LL*y )/ __gcd(x,y) ;
         if(ans<N) 
          ans = multiples_ct[x] + multiples_ct[y] -  multiples_ct[ans] ;
         else
            ans = multiples_ct[x] + multiples_ct[y];
          cout<<ans<<endl;
 
    }
    
    return 0;
}