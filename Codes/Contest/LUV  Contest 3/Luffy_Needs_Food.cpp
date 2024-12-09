
// https://www.hackerearth.com/problem/algorithm/luffy-needs-food/

#include <bits/stdc++.h>
using namespace std;

int main(void)
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, f;
        cin >> n >> k >> f;

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;

            x = (k - x);
            v.push_back({x, y});
        }

        sort(v.begin(), v.end());

        int ans = 0;
        bool canReach = true;
        multiset<int> foodsAvailable;
        int currentIsland = 0;
        for (int i = 1; i < k; i++)
        {
            f--;
            if (v[currentIsland].first == i)
            {
                foodsAvailable.insert(v[currentIsland].second);
                currentIsland++;
            }

            if (f == 0)
            {
                if (foodsAvailable.size() == 0)
                {
                    canReach = false;
                    break;
                }
                else
                {
                    ans++;
                    auto it = --(foodsAvailable.end());
                    f += (*it);
                    foodsAvailable.erase(it);
                }
            }
        }

        cout << ((canReach) ? ans : -1) << endl;
    }

    return 0;
}