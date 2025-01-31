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







int main(void)
{
    init_code();

    int t;
    cin>>t;
    while (t--)
    {
        int a,k,A;
        cin>>a>>k>>A;

        bool flag= true; // Ana
        if(A%2==0)
        {
            if(a==k) 
             flag=0;
            else if(a>k)
             flag=1;
            else if(a<k)
             flag=0;    
        }
        else
        {
            if(a==k) 
             flag=1;
            else if(a>k)
             flag=1;
            else if(a<k)
             flag=0;
        }

        if(flag)
         cout<<"First"<<endl;
        else
         cout<<"Second"<<endl; 
    }
    

    



}