#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> graph;
    vector<int> visited; // 0 = unvisited, 1 = visiting, 2 = visited

    void buildGraph(int numCourses, vector<vector<int>> &prerequisites)
    {
        graph = vector<vector<int>>(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            graph[x].push_back(y);
        }
    }

    bool dfs(int course)
    {
        if (visited[course] == 1) // cycle detected
            return false;

        if (visited[course] == 2) // Already processed
            return true;

        visited[course] = 1;

        for (int neighbor : graph[course])
        {
            if (!dfs(neighbor))
                return false;
        }
        visited[course]=2; // marking as visited
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        buildGraph(numCourses, prerequisites);
        visited = vector<int>(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0)
            {
                if (!dfs(i))
                    return false;
            }
        }
        return true;
    }
};
