// https : // www.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <bits/stdc++.h>
        using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));

        int ct = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    ct++;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        return ct;
    }

private:
    int n, m;
    vector<vector<bool>> vis;
    const vector<pair<int, int>> movements = {
        {-1, 0}, {-1, 1}, {-1, -1}, {0, 1}, {0, -1}, {1, 0}, {1, 1}, {1, -1}};

    bool isValied(int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        vis[i][j] = true;

        for (auto move : movements)
        {
            int x = i + move.first;
            int y = j + move.second;

            if (isValied(x, y) && !vis[x][y] && grid[x][y] == '1')
            {
                dfs(x, y, grid);
            }
        }
    }
};

int main(void)
{

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid;
    for (int i = 0; i < n; i++)
    {
        vector<char> tmp;
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            tmp.push_back(x);
        }
        grid.push_back(tmp);
    }

    Solution s;

    cout << s.numIslands(grid) << endl;
}

/*

    4 2

    0 1
    1 0
    1 1
    1 0



    2 7

    0 1 1 1 0 0 0
    0 0 1 1 0 1 0

*/