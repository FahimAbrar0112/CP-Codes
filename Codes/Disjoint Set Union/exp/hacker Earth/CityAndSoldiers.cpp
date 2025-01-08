#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> parents(N, 0);
vector<int> Size(N, 0);

void make(int v)
{
    parents[v] = v;
    Size[v] = 1;
}

int find(int v)
{
    if (v == parents[v])
        return v;

    return parents[v] = find(parents[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {

        parents[a] = b;

        Size[b] += Size[a];
    }
}

void makeParent(int v)
{
    int par = find(v);
    parents[v] = v;
    parents[par] = v;
}

int main(void)
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            Union(x, y);
        }

        if (op == 2)
        {
            int x;
            cin >> x;
            makeParent(x);
        }

        if (op == 3)
        {
            int x;
            cin >> x;
            cout << find(x) << endl;
        }
    }
}

/*

   5 5
1 1 2
1 3 4
2 3
3 4
3 2



*/