#include<bits/stdc++.h>
using namespace std;

/*  
    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
*/
const int N=1e3+10;
const int INF=1e9+10;

int val[N][N];
int vis[N][N];
int lev[N][N];
int n,m;

vector<pair<int,int>> movements={
                                        //SIDES:
                                        {0,1},{0,-1},{1,0},{-1,0}
                                        //Corners:
                                       // ,{1,1},{-1,1},{1,-1},{-1,-1}
                                
                                };

bool isValid(int i,int j)
{
    return i>=0 && j>=0 && i<n && j<m ;
}



int bfs()
{
    int mx=2;
       
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(mx==val[i][j])
               {
                q.push({i,j});
                lev[i][j]=0;
                vis[i][j]=1;
               }
            }
        }

        int ans=0; 
        while(!q.empty())
        {
            auto v=q.front();
            int v_x=v.first;
            int v_y=v.second;
            q.pop();

            for(auto movement:movements)
            {
                int child_x=movement.first+v_x;
                int child_y=movement.second+v_y;
                if(!isValid(child_x,child_y)) continue;
                if( val[child_x][child_y]==0) continue; 
                if(vis[child_x][child_y]) continue;
                q.push({child_x,child_y});
                lev[child_x][child_y] = lev[v_x][v_y]+1;
                vis[child_x][child_y] =1;
                ans=max(ans,lev[child_x][child_y]);
                
            } 
        }

        bool flag=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(val[i][j]==1 && vis[i][j]==0)
               {    
                  
                    flag=false;
                    break;
               }
            }
        }

     return flag==false? -1:ans;   
}




void reset()
{
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                val[i][j]=0;
                lev[i][j]=INF;
                vis[i][j]=0;
            }
        }
}


int main(int argc,char * argv[])
{   
      
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>val[i][j];
            }
        }

       cout<<bfs()<<endl; 
       
      // reset();

      
    

    



    return 0;
}

/*  

   3  3
   2 1 1
   1 1 0
   0 1 1

    //op 4

   1 2
   0 2

   //op 0

   3 3
   2 1 1 
   0 1 1
   1 0 1

   // -1





*/

/*  
        //SUBMITTED COED ON LEETCODE:  

        //GLOBAL:

        const int N=1e3+10;
        const int INF=1e9+10;

        class Solution {
        public:
            int val[N][N];
            int vis[N][N];
            int lev[N][N];
            int orangesRotting(vector<vector<int>>& val) {

                int mx=2;
                int n=val.size();
                int m=val[0].size();
            
                queue<pair<int,int>> q;

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                    if(mx==val[i][j])
                    {
                        q.push({i,j});
                        lev[i][j]=0;
                        vis[i][j]=1;
                    }
                    }
                }

                int ans=0; 
                while(!q.empty())
                {
                    auto v=q.front();
                    int v_x=v.first;
                    int v_y=v.second;
                    q.pop();

                    for(auto movement:movements)
                    {
                        int child_x=movement.first+v_x;
                        int child_y=movement.second+v_y;
                        if(!isValid(child_x,child_y,val)) continue;
                        if( val[child_x][child_y]==0) continue; 
                        if(vis[child_x][child_y]) continue;
                        q.push({child_x,child_y});
                        lev[child_x][child_y] = lev[v_x][v_y]+1;
                        vis[child_x][child_y] =1;
                        ans=max(ans,lev[child_x][child_y]);
                        
                    } 
                }
                
            bool flag=true;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                    if(val[i][j]==1 && vis[i][j]==0)
                    {    
                        
                            flag=false;
                            break;
                    }
                    }
                }

            return flag==false? -1:ans;   
                
            }

            vector<pair<int,int>> movements={
                                                //SIDES:
                                                {0,1},{0,-1},{1,0},{-1,0}
                                                //Corners:
                                            // ,{1,1},{-1,1},{1,-1},{-1,-1}
                                        
                                            };

            bool isValid(int i,int j,vector<vector<int>>&val)
            {   
                int n=val.size();
                int m=val[0].size();
                return i>=0 && j>=0 && i<n && j<m ;
            }                            
        };


            

*/