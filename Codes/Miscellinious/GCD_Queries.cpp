#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        sort(arr.begin(), arr.end());

        int q;
        cin >> q;

        while (q--)
        {

            int k;
            cin >> k;
            bool found = 1;
            for (int i = 0; i < n; i++)
            {
                if (__gcd(arr[i], k) > 1)
                {
                    cout << arr[i] << " ";
                    auto it = find(arr.begin(), arr.end(), arr[i]);
                    arr.erase(it);
                    n--;
                    found = 0;
                    break;
                }
            }
            if (found)
                cout << arr[0] << " ";
            auto it = find(arr.begin(), arr.end(), arr[0]);
            arr.erase(it);
            n--;
        }
    }
}

/*

1
6
10 12 4 3 7 11
6
2 3 2 5 6 7

*/