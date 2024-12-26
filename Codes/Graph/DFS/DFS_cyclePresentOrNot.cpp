#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
bool vis[N];

bool dfs(int vertex, int par)
{
    // Take action on vertex after entering the vertex:
    vis[vertex] = true;
    bool isLoopExists = false;

    for (int child : g[vertex])
    {
        if (vis[child] && child == par)
            continue;
        if (vis[child])
            return true;
        // Take action on child before entering the child node::
        isLoopExists |= dfs(child, vertex);
        // Take action on child after leaving the child node:
    }
    // Take action on child before leaving the vertex:
    return isLoopExists;
}

int main(int argc, char *argv[])
{

    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool isLoopExists = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        if (dfs(i, 0))
        {
            isLoopExists = true;
            break;
        }
    }
    cout << isLoopExists << endl;

    return 0;
}

/*
        8 5

        1 2
        2 3
        2 4
        3 5
        6 7

//////////////////


        8 6

        1 2
        1 5
        2 3
        2 4
        3 5
        6 7
*/