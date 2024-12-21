// https : // www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/name-count/

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 10;
int fact[N];

int binExp(int a, int b, int m)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    // cout << result << endl;
    return result;
}

/*

        nCr * r! = nPr => (n!)/(n-r)!
                       => (n!/ r!*(n-r)!) *r!
*/

int main(void)
{

    fact[0] = fact[1] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (i * 1ll * fact[i - 1]) % M;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        /*

            kPn

        */
        int ans = fact[k];
        int denom = fact[k-n];

        denom = binExp(denom,M-2,M);

        ans = (ans*1ll*denom)%M;
        cout<<ans<<endl;
    }
}