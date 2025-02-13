#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> graph;
    vector<int> visited; // 0 = unvisited, 1 = visiting, 2 = visited
    vector<int> order;   // Stores the topological order

    void buildGraph(int numNodes, vector<vector<int>> &edges)
    {
        graph = vector<vector<int>>(numNodes);
        for (auto &edge : edges)
        {   
            //  u -> v  mane age u hobe then v;
            //  science nile engineering porte parba
            //  science ->  engineering
            //  So,  engineering neyar prerequisite science


            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v); // Directed edge u → v
        }
    }

    bool dfs(int node)
    {
        if (visited[node] == 1) // Cycle detected
            return false;

        if (visited[node] == 2) // Already processed
            return true;

        visited[node] = 1; // Mark as visiting

        for (int neighbor : graph[node])
        {
            if (!dfs(neighbor))
                return false;
        }

        visited[node] = 2;     // Mark as visited
        order.push_back(node); // Postorder DFS
        return true;
    }

    vector<int> topologicalSort_DFS(int numNodes, vector<vector<int>> &edges)
    {
        buildGraph(numNodes, edges);
        visited = vector<int>(numNodes, 0);
        order.clear();

        for (int i = 0; i < numNodes; i++)
        {
            if (visited[i] == 0)
            {
                if (!dfs(i))
                    return {}; // Cycle detected, no valid order
            }
        }

        reverse(order.begin(), order.end()); // Reverse to get correct order
        return order;
    }
};

// Main function to test the solution
int main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
    int numNodes = 4;

    vector<int> result = sol.topologicalSort_DFS(numNodes, edges);

    if (result.empty())
        cout << "No valid order (Cycle detected)" << endl;
    else
    {
        cout << "Topological Order (DFS): ";
        for (int node : result)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}
