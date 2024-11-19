#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;

vector<pair<int, int> > graph[N];

int main(int argc,char * argv[])
{   
    int n,m;
    cin >> n >> m;

          for(int i=1;i<=m;i++)
          {
            int v1,v2,wt;
            cin >> v1 >> v2>>wt;
            graph[v1].push_back({v2,wt});
            graph[v2].push_back({v1,wt});   
          }
    
          
          //2 ta node /vertex coonected ki na?    O(N)
        /*  
            for(pair<int,int>  child:graph[i])
            {
            if(child.first==j)
            connected;
            else
            not connected; 
            }
        */

        // weight: 
        /*
            for(pair<int,int>  child:graph[i])
            {
                if(child.first==j)
                 child.second
          
            }
        */


    int x,y;
    cout<<"ENTER x and y to get the weight of that nodes X<->y: " ;
    cin >> x >> y;


    cout<<endl<< "WEIGHT of x<->y = ";
        for(pair<int,int>  child:graph[x])
            {
                if(child.first==y)
                 cout<<child.second;
          
            }
    



    return 0;
}

/** 
        WEIGHTED: 
         
         6 9 

         1 3 4
         1 5 3
         3 5 2
         3 4 7
         3 6 8 
         3 2 9
         2 6 1
         4 6 2
         5 6 3


         3 4     
             
             =>Output  7




          // 1 3 4  here 4 is weight

*/