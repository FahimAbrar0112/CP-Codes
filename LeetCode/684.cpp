#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> parent;
    vector<int> Size;

    void make(int v)
    {
        parent[v] = v;
        Size[v] = 1;
    }

    int find(int v)
    {
        if (v == parent[v])
            return v;

        return parent[v] = find(parent[v]); // Path compression
    }

    void Union(int a, int b)
    {
        a = find(a); // a tree will be bigger
        b = find(b); // b tree will  be smaller

        if (a != b)
        {
            // using  union by size   // Or could do union by rank
            //  to make a big and b small let's compare and then swap:
            if (Size[a] < Size[b])
                swap(a, b);
            parent[b] = a;
            Size[a] += Size[b];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        
        int n = edges.size();

        parent = vector<int>(n + 10, 0);
        Size = vector<int>(n + 10, 0);

        for (int i = 1; i <= n; i++)
        {
            make(i);
        }

        for (auto edge : edges)
        {
            int a = edge[0];
            int b = edge[1];

            if (find(a) == find(b))
                return {a, b};

            Union(a, b);
        }

        return {};
    }
};
