#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

long long prefixSum[N];

int main(void)
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {

        int x;
        cin >> x;
        prefixSum[i] = prefixSum[i - 1] + x;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int L, R;
        cin >> L >> R;
        cout << prefixSum[R] - prefixSum[L - 1] << endl;
    }
}

/**
 6
 3 6 2 8 9 2
 4
 2 3
 4 6
 1 5
 3 6



 */