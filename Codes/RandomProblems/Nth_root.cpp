#include<bits/stdc++.h>
using namespace std;

// O( p*log( N*10^d))   => d dig porjonto accurcy chai
// p th root of number N with d decimal accuracy

double eps = 1e-6; // for 5 decimal accuracy 
double multiply(double mid,int n)
{
    double ans = 1.0;
    for(int i=0;i<n;i++)
    {
        ans*=mid;
    }
    return ans;
}

double Nth_root(double x, int n)
{
    double lo=1,hi=x,mid;
    while(hi-lo>eps)
    {
        mid=(lo+hi)/2;
        if( multiply(mid,n) <x )
         lo=mid;
        else
         hi = mid; 
    }
    cout<<setprecision(10)<<lo<<" "<<hi<<endl;
    cout<<pow(x,1.0/n)<<endl;
    return hi ;
}

int main(void)
{
     
    
     while(1)
     {
        double x;
        int n;
        cin>>x>>n;

        Nth_root(x,n);

     }


    return 0;
}