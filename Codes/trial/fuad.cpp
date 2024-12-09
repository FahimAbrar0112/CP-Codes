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

        int lo = 0, hi = n - 1, mid;
        vector<long long>::iterator ptr1 = v.begin();
        vector<long long>::iterator ptr2 = v.begin();

        while (hi - lo > 1)
        {
            mid = (lo + hi) / 2;
            if (v[mid] <= m - 1 - x)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        ptr1 = v.begin() + lo;
        ptr2 = v.begin() + hi;

        ptr1 = (*ptr1 > m - 1 - x) ? ptr1 : ptr2;

        if (ptr1 != v.begin())
            ptr1--;

        cout << max((*ptr1 + x) % m, (v[n - 1] + x) % m) << endl;
    }

    return 0;
}