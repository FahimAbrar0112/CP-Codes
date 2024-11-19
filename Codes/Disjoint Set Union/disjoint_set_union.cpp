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
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        make(i);
    }
    while(k--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }

    int connected_ct=0;
    for(int i=1;i<=n;i++)
    {
        if(find(i)==i) connected_ct++;
    }

    cout<<connected_ct<<endl;


    return 0;
}

/*
    6 4
    1 2
    2 3
    1 3
    4 5


*/
