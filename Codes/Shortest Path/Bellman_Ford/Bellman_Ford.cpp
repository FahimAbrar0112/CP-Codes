// Shortest path, Singe source, Can handle -ve edges, can detect -ve cycle.
// N ta node thakle N-1 bar chalaite hoy loop
// Cz, nth time a changes ashle -ve cycle ase,otherwise -ve cycle nai

/*
        A negative weight cycle in a graph is a cycle (a closed path that starts and ends at the same vertex) where the total sum of the edge weights is negative. This means:

    Sum of edge weights in the cycle  <  0




*/

#include <bits/stdc++.h>
using namespace std;

// Structure to represent a graph edge
struct node
{
    int u, v, wt; // u = source, v = destination, wt = weight
    //   u --> v
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

    // Define edges with their weights (1-based indexing)

    edges.push_back(node(1, 2, 5));
    edges.push_back(node(2, 3, -2));
    edges.push_back(node(2, 6, -3));
    edges.push_back(node(3, 5, 3));
    edges.push_back(node(4, 3, 6));
    edges.push_back(node(4, 5, -2));
    edges.push_back(node(6, 4, 1));

    /*
        edges.push_back(node(1, 2, 2));
        edges.push_back(node(2, 3, -4));
        edges.push_back(node(3, 1, 1));

    */

    int src = 1; // Source node
    int INF = INT_MAX;

    // Initialize distances to all nodes as INF
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

    // Detect negative weight cycles
    bool hasNegativeCycle = false;
    for (auto it : edges)
    {
        if (dist[it.u] != INF && dist[it.u] + it.wt < dist[it.v])
        {
            cout << "Negative weight cycle detected\n";
            hasNegativeCycle = true;
            break;
        }
    }

    // Output the distances if no negative cycle exists
    if (!hasNegativeCycle)
    {
        cout << "Vertex\tDistance from Source\n";
        for (int i = 1; i <= N; i++)
        {
            if (dist[i] == INF)
            {
                cout << i << "\tINF\n"; // Unreachable node
            }
            else
            {
                cout << i << "\t" << dist[i] << "\n"; // Shortest distance
            }
        }
    }

    return 0;
}