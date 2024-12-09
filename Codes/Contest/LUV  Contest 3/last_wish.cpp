#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

bool cmp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
{
    pair<int, int> x, y;
    x = p1.second;
    y = p2.second;

    if ((x.first + x.second) == (y.first + y.second))
        return x.first < y.first;

    return (x.first + x.second) < (y.first + y.second);
}

int main(void)
{
    int t;
    cin >> t;
    int ind = 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, pair<int, int>>> v;

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back({i, {x, y}});
        }

        sort(v.begin(), v.end(), cmp);
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[v[i].first] = i;
        }

        for (auto elm : ans)
        {
            cout << elm << " ";
        }
        cout<<endl;
    }

    return 0;
}
