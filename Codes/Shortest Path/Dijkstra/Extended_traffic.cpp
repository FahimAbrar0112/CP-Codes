#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int INF=1e9+7;

struct node 
{
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) 
    {
        u = first;
        v = second;
        wt = weight;
    }
};

void BellmanFord(int n,vector<int>&dist, vector<node>&edges)
{
    int src=1;
    dist[src]=0;
    
    for(int i = 1;i<=n-1;i++) 
    {
        for(auto it: edges) 
        {
            if(dist[it.u]!=INF && (dist[it.u] + it.wt < dist[it.v])) 
            {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    
   

}

int main(void)
{   
      
    int t;
    cin >> t;
    int increment =1;
    while(t--)
    {   

        int  n;
        cin >> n;
        vector<node> edges;
        vector<int>dist(n+10,INF);
        vector<int>point(n+10,0);

        for(int i=1; i<=n; i++)
        {
            cin>>point[i];
        }

        int e;
        cin >> e;

        for(int i=1; i<=e; i++)
        {
            int x,y;
            cin >> x>>y;
            long long tmp = (point[y]-point[x])*(point[y]-point[x])*(point[y]-point[x]) ;
            edges.push_back(node(x,y,tmp)) ;
            //cout<<x<<" "<<y<<" "<<tmp<<endl;

        }

        BellmanFord(n,dist,edges);
        int q;
        cin >> q;
        cout<<"Case "<< increment<<":"<<endl;
        increment++;
        while(q--)
        {
            int x;
            cin >> x ;
            if(dist[x]<3 || dist[x]==INF)
             cout<<'?'<<endl;
            else
             cout<<dist[x]<<endl; 
        }
    
    }
       
    



    return 0;
}