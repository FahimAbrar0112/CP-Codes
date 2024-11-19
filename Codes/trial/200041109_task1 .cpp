#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int>>> edge;
const int N = 2e5 + 10;
int par[N];
int SIZE[N];

void start(int index)
{
    par[index] = index;
    SIZE[index] = 1;
}
int parent(int index)
{
    int root = index;
    while (root != par[root])
    {
        root = par[root];
    }
    while (index != root)
    {
        int parent = par[index];
        par[index] = root;
        index = parent;
    }
    return root;
}

void UnionN(int index1, int index2)
{
    int par1 = parent(index1);
    int par2 = parent(index2);
    int size1 = SIZE[par1];
    int size2 = SIZE[par2];
    if (size1 > size2)
    {
        par[par2] = par1;
        SIZE[par1] += size2;
    }
    else
    {
        par[par1] = par2;
        SIZE[par2] += size1;
    }
}

int main(void)
{
    while (1)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            start(i);
        }
        int total = 0;
        for (int i = 0; i < m; i++)
        {
            int index1, index2, cost;
            cin >> index1 >> index2 >> cost;
            edge.push_back({cost, {index1, index2}});
            total += cost;
        }
        sort(edge.begin(), edge.end());
        int take = 0;
        for (int i = 0; i < m; i++)
        {
            // cout<<"aaa"<<endl;
            int cost = edge[i].first;
            int index1 = edge[i].second.first;
            int index2 = edge[i].second.second;
            // cout<<index1<<" ssss  "<<index2<<endl;
            if (parent(index1) == parent(index2))
            {
                continue;
            }
            take += cost;
            UnionN(index1, index2);
        }
        cout << total - take << endl;
    }
}

/*

    7 11
    0 1 7
    0 3 5
    1 2 8
    1 3 9
    1 4 7
    2 4 5
    3 4 15
    3 5 6
    4 5 8
    4 6 9
    5 6 11




*/
