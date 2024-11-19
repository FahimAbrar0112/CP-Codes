#include<bits/stdc++.h>
using namespace std;

//Defend The Rohan SPOJ:



const int N=55;
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
            if( dist[v]!=INF && dist[v]+wt <dist[child_v])
            {
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }

}

void reset()
{
    for(int i=0;i<N;i++)
    {
        vis[i]=0;
        dist[i]=INF;
    }
}

void reset_G()
{
    for(int i=0;i<N;i++)
    {
        g[i].clear();
    }
}

int main(int argc,char * argv[])
{


   int t;
   cin>>t;
   int x=1;
   while(t--)
   {    
        reset_G();
        int n;
        cin>>n;
        int arr[n+5][n+5] ;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {

                cin>>arr[i][j];

            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                g[i].push_back({j,arr[i][j]});

            }
        }


        long long ans=0;

        int q;
        cin>>q;

        while(q--)
        {

            int src,dst;
            cin>>src>>dst;


            reset();
            Dijkstra(src);
            ans+=dist[dst];




        }
        cout<<"Case #"<<x<<": "<<ans<<endl;
        x++;
         //cout<<ans<<endl;

   }










    return 0;
}

/*

 1
 3
 0 1 1
 1 0 1
 1 9 0

 2
 2 1
 3 2



*/
