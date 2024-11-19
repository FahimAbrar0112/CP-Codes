#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;

int parent[N];
int Size[N];
vector<pair<int,pair<int,int>>> edges;

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

void reset()
{
    for(int i=0;i<N;i++)
    {
        Size[i]=0;
        parent[i]=0;
    }
    edges.clear();
}

int main(void)
{
   while(true)
   { 
     int n,m;
     cin>>n>>m;
     if(n==0 && m==0) return 0;

     reset();

     
     int total_cost_for_all_wt=0;
     for(int i=0;i<m;i++)
     {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
        total_cost_for_all_wt+=wt;
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
        //cout<<u<<" "<<v<<endl;

     }
     cout<<total_cost_for_all_wt-total_cost<<endl;
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
    0 0



*/
