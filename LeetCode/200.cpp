#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, m;
    vector<vector<bool>> vis;
    vector<pair<int, int>> movements = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool isValied(int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void dfs(int i, int j, vector<vector<char>> &grid)
    {

        vis[i][j] = 1;
        for (auto move : movements)
        {
            int x = move.first + i;
            int y = move.second + j;

            if (isValied(x, y) && grid[x][y] == '1' && !vis[x][y])
            {
                dfs(x, y, grid);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int ct = 0;
        n = grid.size();
        m = grid[0].size();

        vis = vector<vector<bool>>(n, vector<bool>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    ct++;
                    dfs(i, j, grid);
                }
            }
        }

        return ct;
    }
};
