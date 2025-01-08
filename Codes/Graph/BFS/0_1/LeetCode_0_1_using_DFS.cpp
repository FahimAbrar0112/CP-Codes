// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans = 0;
    void dfs(int vertex, int par, vector<vector<pair<int, int>>> &g)
    {

        for (auto &child : g[vertex])
        {
            int first = child.first;
            int sec = child.second;

            if (first == par)
                continue;
            ans += sec;
            dfs(first, vertex, g);
        }
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

        dfs(0, -1, g);
        return ans;
    }
};

int main(void)
{   
    



}