#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return !(a.second > b.second);
    return !(a.first < b.first);
}

int main(void)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);

    q.push({123, 5});
    q.push({123, 1});
    q.push({22, 44});
    q.push({66, 76});
    q.push({123, 10});
    q.push({212, 3});
    q.push({5, 31});
    q.push({500, 1});

    while (!q.empty())
    {
        auto val = q.top();
        cout << val.first << "    " << val.second << endl;
        q.pop();
    }

    return 0;
}