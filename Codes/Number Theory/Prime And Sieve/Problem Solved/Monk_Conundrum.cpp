// https: // www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int multiples_Ct[N];
int hsh[N]; // stores count of each number

void seive()
{
    // n log n
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {  // j is multiple of i
            multiples_Ct[i] += hsh[j];
        }
    }
}

int main(void)
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hsh[x]++;
    }

    seive();

    int t;
    cin >> t;

    while (t--)
    {
        int p, q;
        cin >> p >> q;

        long long lcm = (p * 1ll * q) / __gcd(p, q);
        long long ans = multiples_Ct[p] + multiples_Ct[q];
        if (lcm < N)
            ans -= multiples_Ct[lcm];

        cout << ans << endl;
    }
}