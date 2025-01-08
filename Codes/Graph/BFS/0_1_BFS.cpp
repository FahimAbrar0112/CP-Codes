#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];
vector<int> level(N, INF);
int n, m;

int bfs(int source)
{
    deque<int> q;
    q.push_back(source);
    level[source] = 0;

    while (!q.empty())
    {
        int cur_v = q.front(); 
        q.pop_front();

        for (auto child : g[cur_v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (level[cur_v] + wt < level[child_v]) // level[cur_v] + 1 or  level[cur_v] + 0  level can be changed twice 
            {
                level[child_v] = level[cur_v] + wt;
                if (wt == 1)
                    q.push_back(child_v);
                else
                    q.push_front(child_v);
            }
        }
    }

    return level[n] == INF ? -1 : level[n];
}

int main(int argc, char *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y) // avoids self loop
            continue;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }

    cout << bfs(1) << endl;

    return 0;
}