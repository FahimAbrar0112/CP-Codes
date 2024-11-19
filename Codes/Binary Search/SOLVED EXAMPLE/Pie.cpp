#include<bits/stdc++.h>
using namespace std;

const long double pi = 3.14159265358979323846264338327950;
const long double eps=1e-5;
int N,F;
vector<long double>v;

bool valied(long double vol)
{
    //bool flag=false;
    //double vol = pi*mid*mid;
    int ct=0;
    for(int i=0;i<N;i++)
    {
        if( v[i]/vol >=1)
        {
            ct+= v[i]/vol ;
        }
    }
   return ct>=F+1;
}


int main(void)
{
    int t;
    cin>>t;
    while( t-- )
    {
        
        cin>>N>>F;
        v.clear();
        
        for (int i = 0; i < N; i++)
        {
            double x;
            cin>>x;
            x = pi*x*x;
            v.push_back(x);
            //cout<<x<<" ";
        }
       // cout<<endl ;


        sort( v.begin(), v.end() );

        double lo=0,hi=v[N-1],mid;

        while(hi-lo>eps)
        {
            mid=(hi+lo)/2.0;
            if(valied(mid))
             lo=mid;
            else
             hi=mid; 
            // cout<<valied(mid)<<" ";
        }
        //cout<<endl;
        if(valied(hi))
         cout<<fixed<<setprecision(4)<<hi<<endl;
        else
         cout<<fixed<<setprecision(4)<<lo<<endl; 
        
    }


    return 0;
}

/*

    1
    3 3 
    4  3 3 

3
3 3
4 3 3
1 24
5
10 5
1 4 2 3 4 5 6 5 4 2



*/