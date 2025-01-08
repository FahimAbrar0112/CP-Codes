// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> parents(N);
vector<int> Size(N);

void make(int v)
{
    parents[v] = v;
    Size[v] = 1;
}

int find(int v)
{
    if (parents[v] == v)
        return v;

    return parents[v] = find(parents[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (Size[a] < Size[b])

            swap(a, b);
        parents[b] = a;
        Size[a] += Size[b];
    }
}

int main(void)
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    int k;
    cin >> k;

    for (int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;

        Union(u, v);
    }

    int cc = 0;

    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
            cc++;
    }

    cout << cc << endl;
}