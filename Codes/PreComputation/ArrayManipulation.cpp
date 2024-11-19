#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+ 10;
long long arr[N];

int main(void)
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b, k;

        cin >> a >> b >> k;

        arr[a] += k;
        arr[b + 1] -= k;
    }

    long long val = -1;

    for (int i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
        val = max(val, (long long)arr[i]);
    }
    
    cout << val << endl;
}