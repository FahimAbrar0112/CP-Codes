#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int par[N];
vector<int> depth(N, 0);

void dfs(int v, int p = -1)
{
    par[v] = p;
    for (int child : g[v])
    {
        if (child == p)
            continue;

        dfs(child, v);
    }
}

void func(int v, int p = 0)
{

    for (int child : g[v])
    {
        if (child == p)
            continue;
        depth[child] = depth[v] + 1;
        func(child, v);
    }
}

vector<int> path(int v)
{
    vector<int> ans;
    while (v != -1)
    {
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char *argv[])
{

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int x, y;
    cin >> x >> y;
    // Find LCA
    vector<int> path_x = path(x);

    vector<int> path_y = path(y);
    int min_len = min(path_x.size(), path_y.size());

    int lca = -1;

    for (int i = 0; i < min_len; i++)
    {
        if (path_x[i] == path_y[i])
            lca = path_x[i];
        else
            break;
    }
    // Use LCA  and get distance
    func(lca);
    cout << depth[x] << "   " << depth[y] << endl;
    cout << lca << "      " << depth[x] + depth[y] << endl;

    return 0;
}

/**

        13
        1 2
        1 3
        1 13
        2 5
        3 4
        5 6
        5 7
        5 8
        8 12
        4 9
        4 10
        10 11


        6 8


*/