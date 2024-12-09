#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long n, m;
    cin >> n >> m;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] %= m;
    }
    sort(v.begin(), v.end());
    int q;
    cin >> q;

    while (q--)
    {
        long long x;
        cin >> x;
        x %= m;

        auto ptr = upper_bound(v.begin(), v.end(), m - 1 - x);
        if (ptr != v.begin())
            ptr--;
        cout << max((*ptr + x) % m, ((v[n - 1] + x) % m)) << endl;
    }

    return 0;
}