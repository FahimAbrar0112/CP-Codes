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
        int n;
        cin >> n;
        map<int, int> mp;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }

        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;

            if (mp.find(x) != mp.end())
            {

                while (mp[x] != 0)
                {
                    v.push_back(x);
                    mp[x]--;
                }

                auto it = mp.find(x);
                mp.erase(it);
            }
        }

        for (auto ele : mp)
        {

            while (ele.second != 0)
            {
                v.push_back(ele.first);
                ele.second--;
            }
        }

        for (auto val : v)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}