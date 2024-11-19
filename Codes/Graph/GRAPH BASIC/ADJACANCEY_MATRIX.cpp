#include<bits/stdc++.h>
using namespace std;
 //ADJACENCY MATRIX: 


//Spcae coomplxity of Adjacency AMtrix method is very high = O(N^2)
// if N>10^6 then it will not work ...as we can make 10^5 elements => so graph[10^2][10^2] will be possible
const int N = 1e3+10 ;
int graph[N][N];


int main(int argc,char * argv[])
{   
       int n,m;  //n =nodes   m=edges
       cin >>n>>m;
    
       
       //Unweighted :
       for(int i=0;i<m;i++)
        {
            int v1,v2;
            cin>>v1>>v2;
                
            graph[v1][v2]=1;
            graph[v2][v1]=1;
        }


        //WEIGHTED :
        for(int i=0;i<m;i++)
        {    
          int v1,v2,wt;
          cin>>v1>>v2>>wt;
          graph[v1][v2]=wt;
          graph[v2][v1]=wt;
        }   

        // 2 ta node conencted ki na?    O(1)
        /*  
         
            if(graph[i][j]==1) coonected ; 
            else  not conncted
        */


        // 2 ta ndoe er weight koto?
        /*  
             g[i][j]  korlei hoye jabe
        

        */

}        