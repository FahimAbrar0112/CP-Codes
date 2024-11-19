#include <bits/stdc++.h>
using namespace std;
const int N = 42;

int main(void)
{

    long long int arr[N][N];

    arr[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        arr[i][0] = 1;
        arr[i][i - 1] = 1;
        for (int j = 1; j < i - 1; j++)
        {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}