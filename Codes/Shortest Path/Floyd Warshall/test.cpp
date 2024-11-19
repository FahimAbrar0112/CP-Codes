#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 1e9+10;

long long dist[N][N];


int main(void)
{   
    int n;

      cin >> n;
      for (int i=1; i<=n; i++)
      {
        for(int j=1; j<=n; j++)
        {
            cin >> dist[i][j];
        }
      }  

     // FLOYD WARSHALL CODE:

    // for(int k=2;k<=3;k++)
    // {
         int k = 3;
        for(int i=1;i<=n;i++)
        {   
            for(int j=1;j<=n;j++)
            {       
                
               if(dist[i][k]!=INF && dist[k][j]!=INF) {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]) ;
                cout<<"q";
               }
            }
        }
    //}

    //Printing Distance:
    cout<<endl<<endl;
    for(int i=1;i<=n;i++)
    {
       // if(i==4) continue;
        for(int j=1;j<=n;j++)
        {
            //if(j==4) continue;
            if(dist[i][j]==INF)
            {
                cout<<"I " ;
            }
            else
            {
                cout<<dist[i][j]<<" ";
            }
        }
       cout<<endl; 
    }

        k = 2;
        for(int i=1;i<=n;i++)
        {   
            for(int j=1;j<=n;j++)
            {       
                
               if(dist[i][k]!=INF && dist[k][j]!=INF) 
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]) ;
            }
        }


    //Printing Distance:
    cout<<endl<<endl;
    for(int i=1;i<=n;i++)
    {
       // if(i==4) continue;
        for(int j=1;j<=n;j++)
        {
            //if(j==4) continue;
            if(dist[i][j]==INF)
            {
                cout<<"I " ;
            }
            else
            {
                cout<<dist[i][j]<<" ";
            }
        }
       cout<<endl; 
    }
    

    



    return 0;
}
/** 
4
0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0





*/