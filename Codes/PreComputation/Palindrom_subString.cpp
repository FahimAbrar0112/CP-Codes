#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int arr[26][N];
void reset()
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = 0;
        }
    }
}

int main(void)
{

    int t;

    cin >> t;
    while (t--)
    {
        reset();

        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++)
        {
            arr[s[j] - 'a'][j + 1]++; // 1 based indexing j+1
        }

        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j < s.size(); j++)
            {
                arr[i][j + 1] += arr[i][j];
            }
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            // l--;
            // r--;
            int oddCount = 0;
            for (int i = 0; i < 26; i++)
            {
                int x = arr[i][r] - arr[i][l - 1];
                if (x % 2 != 0)
                    oddCount++;
            }

            if (oddCount > 1)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
}