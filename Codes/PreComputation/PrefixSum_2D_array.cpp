#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int arr[N][N];

int main(void)
{

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + arr[i][j];
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << arr[c][d] - arr[a - 1][d] - arr[c][b - 1] + arr[a - 1][b - 1] << endl;
    }
}