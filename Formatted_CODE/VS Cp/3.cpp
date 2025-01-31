//Pratik Pandey
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define eps 1e-9
#define maxp 100000
#define mod 1000000007
#define sin(s) scanf("%lld",&s);
#define sout(s) printf("%lld\n",s);
#define in(s) cin>>s
#define in2(a,b) cin>>a>>b
#define out(s) cout<<s
#define outs(s,a) cout<<s<<a
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define gear_change ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define nfl(i,n) for(i=0;i<n;i++)
#define sfl(i,s,e) for(i=s;i<e;i++)
#define ufl(i,n) for(i=n-1;i>=0;i--)
ll power(ll x,ll y,ll p)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
			ret=(ret*x)%p;
		y/=2;
		x=(x*x)%p;
	}
	return ret%p;
}
ll inv(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 
void solve()
{
	ll a,b,c,m;
	cin>>a>>b>>c>>m;
	ll t1=power(a,b,m);
	ll t2=inv(c,m);
	cout<<(t1*t2)%m<<'\n';
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	#endif
	gear_change;
	ll test;
    cin>>test;
	// in(test);
	while(test--)
	{
		solve();
	}
}	