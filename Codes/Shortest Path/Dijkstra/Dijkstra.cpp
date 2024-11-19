#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int INF=1e9+10;

vector<pair<int,int>> g[N] ;  // node,wt

vector<int>vis(N,0);
vector<int>dist(N,INF);


void Dijkstra(int source)    // O(V+ E log V)
{
    

    set<pair<int,int>> st;   //wt,node
     
    st.insert({0,source});
    dist[source]=0;

    while(st.size() > 0 )
    {
        auto node = *st.begin();
        int v = node.second;
        int node_dist = node.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v]=1;
        for(auto child:g[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if(dist[v]+wt <dist[child_v])
            {
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});
            }
        }
        

    }

}


int main(int argc,char * argv[])
{   
      
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt}); //Directedgraph
        g[y].push_back({x,wt});
                                //Undirected graph :  g[y].push_back({x,wt});
    }

    Dijkstra(1);
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }



    return 0;
}

/*

    4 3

    2 3 1
    2 1 1
    3 4 1



*/