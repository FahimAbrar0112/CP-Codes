// https://www.hackerearth.com/problem/algorithm/too-lazy-to-name-the-question-ii/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

int main(void)
{

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    set<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        st.insert(v[i]);
    }

    // for(auto x:v)
    // {
    //     cout<<x.first<<"  "<<x.second<<endl;
    // }

    long long area_min = INT_MAX, area_max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i].first == v[j].first)
                continue;
            if (v[i].second == v[j].second)
                continue;

            pair<int, int> p1, p2;
            p1 = v[i];
            p2 = v[j];

            if (p1.first > p2.first)
                swap(p1, p2);

            // Other 2 points:
            pair<int, int> p3, p4;
            p3 = {p1.first, p2.second};
            p4 = {p2.first, p1.second};

            if (st.count(p3) && st.count(p4))
            {
                long long area = abs(p2.first - p1.first) * abs(p2.second - p1.second);

                area_min = min(area_min, area);
                area_max = max(area_max, area);
            }
        }
    }
    if (area_min == INT_MAX)
        cout << -1 << endl;
    else
        cout << area_max - area_min << endl;
    return 0;
}