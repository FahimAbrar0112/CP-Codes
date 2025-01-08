#include <bits/stdc++.h>
using namespace std;

/*
    Shortest path algorithm.
    Graph Type: Works only on graphs with non-negative edge weights.

*/
const int INF = INT_MAX;
vector<vector<pair<int, int>>> g;   // node , wt
vector<bool> vis;
vector<int> dist;

void Dijkstra(int source) // O(V+ E log V)
{

    set<pair<int, int>> st; // wt,node

    st.insert({0, source});
    dist[source] = 0;

    while (!st.empty())
    {
        auto node = *st.begin();
        int v = node.second;
        int node_dist = node.first;
        st.erase(st.begin());
        if (vis[v])
            continue;
        vis[v] = 1;
        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main(int argc, char *argv[])
{

    int n, m;
    cin >> n >> m;

    g.resize(n + 5);
    vis.resize(n + 5, 0);
    dist.resize(n + 5, INF);

    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt}); // Directedgraph
        g[y].push_back({x, wt});
        // Undirected graph :  g[y].push_back({x,wt});
    }

    Dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}

/*

    4 3

    2 3 1
    2 1 1
    3 4 1


    6 9
    1 2 1
    1 3 5
    2 3 2
    2 4 2
    2 5 1
    3 5 2
    4 5 3
    5 6 2
    4 6 1




*/