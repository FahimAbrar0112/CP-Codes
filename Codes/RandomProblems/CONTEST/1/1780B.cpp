#include<bits/stdc++.h>
using namespace std;



int main(int argc,char * argv[])
{   
    int  t;
    cin >> t;

    while (t--)
    {
        long long  n;
        cin >> n;

        vector<long long>v(n+10,0);
        vector<long long>sum(n+10,0);

        for(int i=1;i<=n;i++)
        {
            cin >> v[i];
        }
        
        for(int i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+v[i];
        }

        long long  gc=0;

        for(int i=1;i<n;i++)
        {
            gc= max( gc ,  __gcd(sum[i],sum[n] -sum[i]) );
        }
        cout<<gc<<endl;
     

       

    }
    

    



    return 0;
}