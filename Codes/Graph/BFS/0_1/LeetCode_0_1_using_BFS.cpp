// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bfs(vector<vector<pair<int, int>>> &g)
    {
        int ans = 0;
        int n = g.size();
        vector<bool> vis(n, false);

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = 1;

        while (!q.empty())
        {
            auto pair = q.front();
            q.pop();
            int vertex = pair.first;
            int wt = pair.second;

            vis[vertex] = 1;
            ans += wt;

            for (auto child : g[vertex])
            {
                if (vis[child.first])
                    continue;
                q.push(child);
            }
        }
        return ans;
    }

    int minReorder(int n, vector<vector<int>> &connections)
    {

        vector<vector<pair<int, int>>> g(n);
        for (auto &connection : connections)
        {
            int first = connection[0];
            int sec = connection[1];

            g[first].push_back({sec, 1});

            g[sec].push_back({first, 0});
        }

        return bfs(g);
    }
};

int main(void)
{
}