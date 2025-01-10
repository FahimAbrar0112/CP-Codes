// https : // vjudge.net/problem/CSES-1675

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> parents(N);
vector<int> Size(N);

void make(int v)
{
    parents[v] = v;
    Size[v] = 1;
}

int find(int v)
{
    if (v == parents[v])
        return v;
    return parents[v] = find(parents[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
            swap(a, b);
        parents[b] = parents[a];
        Size[a] += Size[b];
    }
}
int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 1; i <= m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back({wt, {u, v}});
    }

    sort(edges.begin(), edges.end());

    long long totalCost = 0;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    for (auto edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        u = find(u);
        v = find(v);

        if (u != v)
        {
            Union(u, v);
            totalCost += wt;
        }
    }

    // Check whether all cities can be traversed or not;

    bool isPossible = 1;

    for (int i = 1; i <= n; i++)
    {
        if (find(1) != find(i))
        {
            isPossible = 0;
            break;
        }
    }

    if (isPossible)
        cout << totalCost << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}