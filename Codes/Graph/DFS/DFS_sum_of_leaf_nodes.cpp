#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

vector<int> g[N];
vector<int> sum(N, 0);

void dfs(int vertex, int par = 0)
{

    if (g[vertex].size() == 1)
        sum[vertex] += vertex;

    for (int child : g[vertex])
    {
        if (child == par)
            continue;

        dfs(child, vertex);

        sum[vertex] += sum[child];
    }
}

int main(int argc, char *argv[])
{

    int n; // n no of nodes.  n node thakle n-1 ta edge thakbe.
    cin >> n;

    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);

    cout << "Node " << "SUM:  " << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << i <<"       "<< sum[i] << "      " << endl;
    }

    return 0;
}

/*
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




*/