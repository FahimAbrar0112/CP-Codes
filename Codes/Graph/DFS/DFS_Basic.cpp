#include<bits/stdc++.h>
using namespace std;

const int N =1e5+10;

//Werighted:
//vector<pair<int,int>>g[N];


//unweighted:
vector<int>g[N];
bool vis[N];

void dfs(int vertex)
{
    //Take action on vertex after entering the vertex:
      // if(vis[vertex]) return;
    vis[vertex] =true;
    for(int child: g[vertex])
    {
        cout<<"parent:"<<vertex<<" child:"<<child<<endl;
        if(vis[child]) continue;
        //Take action on child before entering the child node::
        dfs(child);
        // Take action on child after leaving the child node:
        
    }
    //Take action on vertex before leaving the vertex:

}


int main(int argc,char * argv[])
{   
      
    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);


    



    return 0;
}

/** 

         6 9 

         1 3
         1 5
         3 5
         3 4
         3 6
         3 2
         2 6
         4 6
         5 6
         

*/