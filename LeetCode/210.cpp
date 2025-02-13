#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> graph;
    vector<int> visited; // 0 = unvisited, 1 = visiting, 2 = visited
    vector<int> order;

    void buildGraph(int numCourses, vector<vector<int>> &prerequisites)
    {
        graph = vector<vector<int>>(numCourses);
        for (auto &p : prerequisites)
        {
            int x = p[0], y = p[1];
            graph[y].push_back(x); // Corrected direction: y → x (y must be done before x)
        }
    }

    bool dfs(int course)
    {
        if (visited[course] == 1) // Cycle detected
            return false;

        if (visited[course] == 2) // Already processed
            return true;

        visited[course] = 1; // Mark as visiting

        for (int neighbor : graph[course])
        {
            if (!dfs(neighbor))
                return false;
        }

        visited[course] = 2; // Mark as visited
        order.push_back(course);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        buildGraph(numCourses, prerequisites);
        visited = vector<int>(numCourses, 0);
        order.clear();

        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0)
            {
                if (!dfs(i))
                    return {}; // Return empty list if cycle is detected
            }
        }

        reverse(order.begin(), order.end()); // Reverse to get correct topological order
        return order;
    }
};

// Main function for testing
int main()
{
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int numCourses = 4;

    vector<int> result = sol.findOrder(numCourses, prerequisites);

    if (result.empty())
        cout << "No valid course order (Cycle detected)" << endl;
    else
    {
        cout << "Valid Course Order: ";
        for (int course : result)
            cout << course << " ";
        cout << endl;
    }

    return 0;
}
