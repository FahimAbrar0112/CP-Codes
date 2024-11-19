#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> g[N];
int depth[N],height[N];


void dfs(int vertex,int par=0)
{
     for(int child: g[vertex])
     {
         if(child==par) continue;
         depth[child] = depth[vertex]+1;
         dfs(child,vertex);
         height[vertex]=max(height[vertex],height[child]+1);
     }
}


int main(int argc,char * argv[])
{   
      
    int n; // n no of nodes.  n node thakle n-1 ta edge thakbe.
    cin>>n;

    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);

    cout<<"Node "<<" depth "<<"HEIGHT" <<endl;

    for(int i=1;i<=n;i++)
    {
        cout<<i<<"       "<<depth[i]<<"         "<<height[i]<<endl;
    }

    



    return 0;
}

/*
        13
        
        1 2
        1 3
        1 13
        2 5
        3 4
        5 6
        5 7
        5 8
        8 12
        4 9
        4 10
        10 11
        



*/