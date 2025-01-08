#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int INF = INT_MAX;
vector<int> g[N];
vector<int> level(N, INF);

/*

    NOTE:
    in normal bfs level of any vertex can be chcanged only once.
    but in 0-1 bfs, level can be changed twice , because 
    it can be changed for 1 or 0 as the vertex maybe connected through 2 edges , one edge has wt=1 so it will change the level once, then one edge having wt=0 will cause the level to change then.


*/
void bfs(int source)
{
    queue<int> q;

    q.push(source);
    level[source] = 0;

    while (!q.empty())
    {
        int current_v = q.front();
        q.pop();

        for (auto child : g[current_v])
        {
            if (level[child] == INF)  // level akbar change hoy only tai == diye check diso
            {
                q.push(child);
                level[child] = level[current_v] + 1;
            }
        }
    }
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

    cout << endl;
    bfs(1);
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << level[i] << endl;
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