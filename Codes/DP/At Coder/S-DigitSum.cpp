#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int M = 1e9 + 7;
const int N = 1e4 + 10;
/*
    //  10^2 => 100=> 3 dig.
        so, 10^10000 => 10000+1 dig => 1e4

*/
string K;
ll D;
ll dp[N][2][105];

ll go(ll index, bool small_taken, ll sum_of_digits)
{

    if (index == (ll)K.size())
        return sum_of_digits % D == 0;

    ll &ans = dp[index][small_taken][sum_of_digits];

    if (ans != -1)
        return ans;

    ans = 0;
    ll lo = 0, hi = small_taken ? 9 : (K[index] - '0');

    for (int digit = lo; digit <= hi; digit++)
    {

        ans += go(index + 1, small_taken || (digit < K[index] - '0'), (sum_of_digits + digit) % D);
        ans %= M;
    }
    return ans % M;
}

int main(void)
{
    memset(dp, -1, sizeof(dp));
    cin >> K >> D;
    cout << (go(0, 0, 0) - 1 + M) % M << "\n";
    
}
/*

    12
    50

*/
