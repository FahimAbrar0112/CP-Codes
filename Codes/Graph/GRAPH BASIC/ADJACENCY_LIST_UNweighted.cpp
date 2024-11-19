#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;

vector<int>graph[N];



int main(int argc,char * argv[])
{   
    int n,m;
    cin >> n >> m;
    
    for(int i=1;i<=m;i++)
    {
      int v1,v2;
      cin >> v1 >> v2;
      graph[v1].push_back(v2);
      graph[v2].push_back(v1);   
    }
     
   
    //2 ta node /vertex coonected ki na?    O(N)
    /*  
        for(int child:graph[i])
        {
          if(child==j)
           connected;
          else
           not connected; 
        }
    */

    



    return 0;
}

/*  

      UNWEIGHTED: 
         
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