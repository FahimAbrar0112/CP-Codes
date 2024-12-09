// https://www.hackerearth.com/problem/algorithm/help-joe-ii/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;

        long long maxV = -1;
        for (auto value : v)
        {
            maxV = max(((value + x) % m), maxV);
        }
        cout << maxV << endl;
    }

    return 0;
}