#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, x;
        cin >> n;
        multiset<int> gadgets;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            gadgets.insert(x);
        }
        // vector<int>v;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            int ct_x = gadgets.count(x);
            while (ct_x--)
            {
                cout << x << " ";
            }
            gadgets.erase(x);
        }

        for (auto val : gadgets)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}