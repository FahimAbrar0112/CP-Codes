#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;

int parent[N];
int Size[N];

void make(int v)
{
    parent[v] =v;
    Size[v]=1;
}

int find(int v)
{
    if(v==parent[v]) return v;
    
      return  parent[v]=find(parent[v]);     // Path compression
}

void Union(int a,int b)
{
    a=find(a);   // a tree will be bigger
    b=find(b);  //b tree will  be smaller

    if(a!=b)
    {   
        //using  union by size   // Or could do union by rank 
        // to make a big and b small let's compare and then swap:
        if(Size[a]<Size[b])
         swap(a,b);
        parent[b]=a;
        Size[a]+=Size[b];
    }
}

int main(void)
{
     int n,m;
     cin>>n>>m;
     vector<pair<int,pair<int,int>>> edges;
     for(int i=0;i<m;i++)
     {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
     } 
     
     sort(edges.begin(),edges.end());
     
     for(int i=1;i<=n;i++)
     {
        make(i);
     }
     
     int total_cost=0;
     for(auto &edge:edges)
     {
        int wt = edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        total_cost+=wt;
        cout<<u<<" "<<v<<endl;

     }
     cout<<total_cost<<endl;

    //  for(int i=1;i<=n;i++)
    //  {
    //     cout<<i<<"  "<<parent[i]<<endl;
    //  }

    return 0;
}

/*
    6 9
    5 4 9
    1 4 1
    5 1 4
    4 3 5
    4 2 3
    1 2 2
    3 2 3
    3 6 8
    2 6 7




*/
