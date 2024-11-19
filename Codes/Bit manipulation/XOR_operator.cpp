#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;

/*

    x^x=0
    x^0=x 
    x^y^z = x^z^y = y^x^z

*/

void Swap(int &a,int &b)
{
    a=a^b;
    b=b^a;
    a=a^b;
     
}

int main(void)
{   
//      int a=5,b=10;
//      cout<<a<<" "<<b<<endl;
//      Swap(a,b);
//      cout<<a<<" "<<b<<endl;

     int n;
     cin>>n;

     int ans=0;
     for(int i=0;i<n;i++)
     {
        int x;
        cin>>x;
        ans^=x;
     }

    
     cout<<ans<<endl; 



    return 0;
}