// https://codeforces.com/contest/1245/problem/D
#include <bits/stdc++.h>
using namespace std;

const int N = 2000+10;
const int INF = INT_MAX;

int parent[N];
int Size[N];

void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}

int find(int v)
{
    if (v == parent[v])
        return v;

    return parent[v] = find(parent[v]); // Path compression
}

void Union(int a, int b)
{
    a = find(a); // a tree will be bigger
    b = find(b); // b tree will  be smaller

    if (a != b)
    {
        // using  union by size   // Or could do union by rank
        //  to make a big and b small let's compare and then swap:
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main(void)
{
    int n;
    cin >> n;
    vector<pair<int, int>> cities(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;

        cities[i].first = x;
        cities[i].second = y;
    }

    vector<int> c(n + 1); // cost_of_power_house
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    vector<int> k(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }

    vector<pair<long long, pair<int, int>>> edges;

    for (int i = 1; i <= n; i++)
    {
        edges.push_back({c[i], {0, i}});
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int distance = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);

            long long cost = distance * 1ll * (k[i] + k[j]);
            edges.push_back({cost, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i <= n; i++)
    {
        make(i);
    }

    long long total_cost = 0;

    vector<int> powerStations;
    vector<pair<int, int>> connections;

    for (auto &edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (find(u) == find(v))
            continue;
        Union(u, v);
        total_cost += wt;
        if (u == 0 || v == 0)
        {
            powerStations.push_back(max(u, v));
        }
        else
        {
            connections.push_back({u, v});
        }
        // cout << u << " " << v << endl;
    }
    cout << total_cost << endl;

    cout << powerStations.size() << endl;
    for (auto powerStation : powerStations)
    {
        cout << powerStation << " ";
    }

    cout << endl;
    cout << connections.size() << endl;
    for (auto connection : connections)
    {
        cout << connection.first << " " << connection.second << endl;
    }

    return 0;
}

/*
    3
    2 1
    1 2
    3 3
    23 2 23
    3 2 3




*/
