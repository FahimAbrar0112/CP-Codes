// https : // codeforces.com/contest/1036/problem/C

#include <bits/stdc++.h>
using namespace std;

#define ll long long

string S;
ll dp[20][2][4];

ll go(ll index, bool small_taken, ll non_zero_digits)
{
    if (non_zero_digits > 3)
        return 0;
    if (index == S.size())
        return 1;

    ll &ans = dp[index][small_taken][non_zero_digits];

    if (ans != -1)
        return ans;

    ans = 0;
    ll lo = 0, hi = (small_taken ? 9 : S[index] - '0');

    for (ll digit = lo; digit <= hi; digit++)
    {
        ans += go(index + 1, small_taken || (digit < S[index] - '0'), non_zero_digits + (digit != 0));
    }

    return ans;
}

ll Solve(ll N)
{
    memset(dp, -1, sizeof(dp));
    S = to_string(N);

    return go(0, 0, 0);
}

int main(void)
{
    // for faster i/o ...used in cp when every milisecond is important.
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll L, R;
        cin >> L >> R;

        cout << Solve(R) - Solve(L - 1) << "\n";
    }
}
/*
        4
        1 1000
        1024 1024
        65536 65536
        999999 1000001

*/