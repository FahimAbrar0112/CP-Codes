#include<bits/stdc++.h>
using namespace std;

const long long N=1e5+10;
const long long INF= 1e11+99 ;
vector<pair<long long,long long> > g[N];
bool vis[N];
vector<long long> dist(N,INF);
long long par[N] ;


void Dijkstra(long long src)
{
    set<pair<long long,long long> > st ;
    st.insert({0,src});
    dist[src]=0;
    par[src]=-1;

    while(st.size()>0)
    {
        auto node = *st.begin();
        long long v = node.second;
        long long node_v=node.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v]=1;

        for(auto child:g[v])
        {
            long long child_v=child.first;
            long long wt=child.second;
            if(dist[v]+wt<dist[child_v])
            {
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});
                par[child_v]=v; 
              //  cout<<v<<" ";
            }
        }
    }
}


int main(void)
{
    long long n,e;
    cin >> n >> e;
    for(long long i=1;i<=e;i++)
    {
        long long x,y,wt;
        cin >> x >> y >> wt;

        g[x].push_back({y,wt});
        g[y].push_back({x,wt});


    }
    
    Dijkstra(1);
    //cout<<"Dijkstra"<<endl;
    vector<long long> parent;

    

    if(vis[n])
    {   
        parent.push_back(n);
        while(par[n]!=-1)
        {   
           // cout<<parent[n]<<endl;
            parent.push_back(par[n]);
            n=par[n];

        }
        reverse(parent.begin(),parent.end());

        for(auto it:parent)
        {
            cout<<it<<" ";
        }
    }
    else
    cout<< -1<<endl;
    
     
   

}