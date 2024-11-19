#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        int result = 1;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            result = ((result % 10) * (x % 10)) % 10;
        }

        cout << ((result == 2 || result == 3 || result == 5) ? "YES" : "NO") << endl;
        // cout<< result<<endl;
    }
}