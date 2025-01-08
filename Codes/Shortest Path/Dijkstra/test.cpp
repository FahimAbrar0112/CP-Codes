#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u, v, wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

int main()
{
    int N = 6, m = 7; // N = number of nodes, m = number of edges
    vector<node> edges;

    // NODES: 1 2 3 4 5 6 (1-based indexing)
    edges.push_back(node(1, 2, 5));
    edges.push_back(node(2, 3, -2));
    edges.push_back(node(2, 6, -3));
    edges.push_back(node(3, 5, 3));
    edges.push_back(node(4, 3, 6));
    edges.push_back(node(4, 5, -2));
    edges.push_back(node(6, 4, 1));

    int src = 1; // Source node
    int INF = INT_MAX;

    // Use N+1 size for 1-based indexing
    vector<int> dist(N + 1, INF);
    dist[src] = 0;

    // Relax all edges (N-1) times
    for (int i = 1; i <= N - 1; i++)
    {
        for (auto it : edges)
        {
            if (dist[it.u] != INF && dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    // Cycle detection
    bool flag = false;
    for (auto it : edges)
    {
        if (dist[it.u] != INF && dist[it.u] + it.wt < dist[it.v])
        {
            cout << "Negative weight cycle detected\n";
            flag = true;
            break;
        }
    }

    // Print distances
    if (!flag)
    {
        cout << "Vertex\tDistance from Source\n";
        for (int i = 1; i <= N; i++)
        {
            if (dist[i] == INF)
                cout << i << "\t" << "INF" << "\n";
            else
                cout << i << "\t" << dist[i] << "\n";
        }
    }

    return 0;
}
