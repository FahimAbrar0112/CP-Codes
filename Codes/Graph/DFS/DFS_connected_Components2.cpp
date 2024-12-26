#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;

vector<int> current_CC;
vector<vector<int>> connected_components;
void dfs(int index)
{
    visited[index] = 1;
    current_CC.push_back(index);
    for (auto child : g[index])
    {
        if (!visited[child])
            dfs(child);
    }
}

int main(void)
{
    int n, m;
    cin >> n >> m;

    // Initialize adjacency list and visited array
    g.resize(n + 1); // 1 based indexing
    visited.resize(n + 1, false);

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i);
            connected_components.push_back(current_CC);
            current_CC.clear();
        }
    }

    cout << count << endl;

    for (auto ccs : connected_components)
    {
        for (auto val : ccs)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}