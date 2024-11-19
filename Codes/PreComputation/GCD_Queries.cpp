#include <bits/stdc++.h>
using namespace std;

int main(void)
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        int arr[n + 10];
        int arrF[n + 10], arrB[n + 10];
        arrF[0] = arrB[0] = arrF[n + 1] = arrB[n + 1] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 1, j = n; i <= n && j >= 1; i++, j--)
        {
            arrF[i] = __gcd(arrF[i - 1], arr[i]);
            arrB[j] = __gcd(arrB[j + 1], arr[j]);
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << __gcd(arrF[l - 1], arrB[r + 1]) << endl;
        }
    }
}