#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
//Code starts from here:

const int N = 2e6+7;
int hp[N]; //stores heighest prime of any number 
bool canRemove[N];
bool hsh[N];

vector<int> distinctPF(int x)
{
    vector<int> ans;

    
    while(x>1)
    {
       int heighestP = hp[x];
       while(x%heighestP == 0)
       {
         x/=heighestP;
       }
       ans.push_back(heighestP);

    }
   return ans; 


}




int main(void)
{
   init_code();

    for(int i=2;i<N;i++)
    {
       if(hp[i]==0) //hp[i]==0 means hp[i] is a prime.
       {
            for(int j=i;j<N;j+=i)
            {
                hp[j]=i;
            }
       } 
    }

    


    int n,q;
    cin>>n>>q;
    vector<int> value(n+10,0);
    for(int i=1;i<=n;i++)
    {
         int x;
         cin>>x;
         hsh[x]=1;
    }

    for(int i=2;i<=N;i++)
    {
        if(hsh[i])
        {
            for(long long j=i;j<=N;j*=i)
            {
                canRemove[j]=1;
            }
        }
        
    }

    while (q--)
    {
        int x;
        cin>>x;
        vector<int>pf =distinctPF(x);
        bool isPossible=false;

        for(int i=0;i<pf.size();i++)
        {
            for(int j=i;j<pf.size();j++)
            {
                ll product = pf[i]*pf[j];
                if( (i==j) && (x%product!=0) ) continue;
                int toRemove = x/product;
                if(canRemove[toRemove] || toRemove==1)
                {
                    isPossible=1;
                    break;
                }
            }
           if(isPossible) 
            break; 
        }

        cout<<(isPossible?"YES":"NO")<<endl;
    }
}