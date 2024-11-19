#include<bits/stdc++.h>
using namespace std;
#define ll Long Long
#define pb push_back
#define fr(a,b) for(int i=a; i < b; i++)
#define rep(i,a,b) for(int i=a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(),(x).end()
#define prBouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<<ll,ll>>
#define goog(tno) cout<< "Case #" << tno << ": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x;cin>>x
void init_code(){ 
    
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
}
// Code starts from here:

/*

2
1
2
*/

long long setBitCT(long long x)
{
    long long ct=1;
     
    while(x>1)
    {  
        if(x&1)
        {
            ct++;
        }
         
        x>>=1;
    }
   return ct; 
}




int main(void)
{
    init_code();

    int t;
    cin>>t;
    while(t--)
    {
        //cout<<"tt"<<endl;
        long long x;
        cin>>x;
        cout<< setBitCT(x) <<endl;
    }        
    



}