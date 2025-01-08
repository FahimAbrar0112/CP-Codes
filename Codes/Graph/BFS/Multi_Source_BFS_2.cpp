#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int n, m;
vector<vector<int>> vals;
vector<vector<int>> level;
vector<vector<bool>> vis;
vector<pair<int, int>> movements = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}, 
    {-1, -1}, {-1, 1}, {1, 1}, {1, -1}
};

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vals[i][j] = 0;
            level[i][j] = INF;
            vis[i][j] = false;
        }
    }
}

bool isValied(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

int bfs()
{
    int max_v = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            max_v = max(max_v, vals[i][j]);
        }
    }

    // Multi Source bfs:
    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vals[i][j] == max_v)
            {
                q.push({i, j});
                vis[i][j] = 1;
                level[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        int vertex_x = p.first;
        int vertex_y = p.second;

        for (auto movement : movements)
        {

            int child_x = vertex_x + movement.first;
            int child_y = vertex_y + movement.second;
            if (!isValied(child_x, child_y) || vis[child_x][child_y])
                continue;

            q.push({child_x, child_y});
            vis[child_x][child_y] = 1;
            level[child_x][child_y] = level[vertex_x][vertex_y] + 1;
            ans = max(ans, level[child_x][child_y]);
        }
    }
    return ans;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m;
        vals.resize(n, vector<int>(m));
        level.resize(n, vector<int>(m, INF));
        vis.resize(n, vector<bool>(m, false));

        reset();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)

            {
                cin >> vals[i][j];
            }
        }

        cout << bfs() << endl;
    }
}