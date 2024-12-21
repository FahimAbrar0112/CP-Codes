#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 10;
int fact[N];

long long binExp(long long a, long long b, long long m)
{

    long long result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
            // cout<<result<<" ";
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    // cout<<endl<<result<<endl;
    return result;
}

int main(void)
{
    fact[0] = fact[1] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (i * 1LL * fact[i - 1]) % M;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        // long long ans = fact[k] ;
        // ans =  (ans*1ll*fact[n])%M;
        // long long denum = (fact[n]*1LL*fact[k-n]) % M ;
        //  denum=binExp(denum,M-2,M);
        //  ans = (ans*1LL* denum) % M ;
        // cout<<ans<<endl;

        long long ans = fact[n];
        long long denom = (fact[k] * 1ll * fact[n - k]) % M;
        ans = (ans * 1LL * binExp(denom, M - 2, M)) % M;
        cout << ans << endl;
    }

    return 0;
}