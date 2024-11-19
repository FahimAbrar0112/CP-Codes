 #include<bits/stdc++.h>
using namespace std;

const int N =1e5+10;
const int M=1e9+7;
vector<int>g[N];
int subtree_sum[N];
int val[N];


void dfs(int vertex,int par=-1)
{
    //Take action on vertex after entering the vertex:
    subtree_sum[vertex]+=val[vertex];
    for(int child: g[vertex])
    {
        //Take action on child before entering the child node::
        if(child==par) continue;
        dfs(child,vertex);
        subtree_sum[vertex] +=subtree_sum[child];
        // Take action on child after leaving the child node:
        
    }
    //Take action on child before leaving the vertex:

}


int main(int argc,char * argv[])
{   
      
    int n;
    cin>>n;

    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }


    cout<< endl <<"ENTER weight: ";
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    
    dfs(1);
    long long ans=0;
    for(int i=2;i<=n;i++)
    {
        int part1=subtree_sum[i];
        int part2=subtree_sum[1]-part1;
        ans=max(ans,(part1*1LL*part2)%M);
    }
    cout<<ans<<endl;

 
    
   



    return 0;
}

/*  
        4
        1 2
        1 4
        4 3



        10 5 12 6


        output is : 270 



        




*/