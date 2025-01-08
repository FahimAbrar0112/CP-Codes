// https://vjudge.net/problem/CSES-1675
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int Wize[N];

//make -> new node
//find -> parent of group
//union -> a,b
void make(int v)
{
    parent[v] = v;
}
int find(int v)
{
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]); // Path compression
}
void Union(int a,int b)
{
    a = find(a);
    b = find(b);
    if(a!=b)
    {
        // Union by size
        if(Wize[a]<Wize[b])
            swap(a,b);
        parent[b] = a;
        Wize[a]+=Wize[b];
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back({wt,{u,v}});
    }
    long long TOTAL_COST = 0;
    sort(edges.begin(), edges.end());
    for(int i = 1;i<=n ;i++) make(i);
    for(auto &edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u) == find(v)) continue;
        Union(u,v);
        TOTAL_COST += wt;
    }
    int flag = 0;
    for(int i=1;i<n;i++)
    {
        if(find(i)!=find(i+1))
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
        cout<<TOTAL_COST<<endl;
}

/*

        5 6
            1 2 3
            2 3 5
            2 4 2
            3 4 8
            5 1 7
            5 4 4


*/