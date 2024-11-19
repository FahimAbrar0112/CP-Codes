#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
const int INF=1e9+10;
vector<vector<int> > val;
bool vis[N][N] ;
int n,m;

int perM=0;

void dfs(int i,int j)
{
   
    if(i<0 || j<0 || i>=n || j>=m)  
    {
        return ;
    }

    if(val[i][j]==0) return ;
    if(vis[i][j]) return ;

    vis[i][j] =1;

    // if(i+1<0 || j<0 || i+1>=n || j>=m || val[i+1][j] == 0 ) perM++;
    // if(i<0 || j+1<0 || i>=n || j+1>=m || val[i][j+1] == 0 ) perM++;
    // if(i-1<0 || j<0 || i-1>=n || j>=m || val[i-1][j] == 0 ) perM++;
    // if(i<0 || j-1<0 || i>=n || j-1>=m || val[i][j-1] == 0 ) perM++;

    if(i+1>=n || val[i+1][j] == 0 ) perM++;
    if(j+1>=m || val[i][j+1] == 0 ) perM++;
    if(i-1<0  || val[i-1][j] == 0 ) perM++;
    if(j-1<0  || val[i][j-1] == 0 ) perM++;
    
    dfs(i+1,j) ;   
    dfs(i,j+1) ;   
    dfs(i-1,j) ;    
    dfs(i,j-1) ;   
}

int islandPerimeter() 
{   

    bool flag=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) 
        {
            if(val[i][j]==1)
            {
                dfs(i,j);
                flag=0;
                break;
            }
        }
        if(!flag) break;
    }

    return perM;

}

int main(int argc,char * argv[])
{   
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {   
       vector<int> tmp; 
        for(int j=0;j<m;j++) 
        {   
            int x;
            cin>>x;
            tmp.push_back(x);
        }
       val.push_back(tmp) ;
    }

    cout<<islandPerimeter()<<endl;
    
 

    return 0;
}

/** 

    4 4
    0 1 0 0 
    1 1 1 0
    0 1 0 0
    1 1 0 0 
    
    //16

    1 1
    1

    // 4

    1 2
    1 0

    //4

    5 3
    0 0 0
    0 1 0
    0 1 0
    0 1 0
    0 0 0
    
    //8
*/


/*

    #include<bits/stdc++.h>
    using namespace std;

    const int N=1e3+10;
    const int INF=1e9+10;
    
    class Solution {
    public:

        
        int perM=0;
        int n,m;
        vector<vector<int> > val;
        bool vis[N][N] ;



    int islandPerimeter(vector<vector<int>> &val) 
        {       
            n=val.size();
            m=val[0].size();

            bool flag=1;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++) 
                {
                    if(val[i][j]==1)
                    {
                        dfs(i,j,val);
                        flag=0;
                        break;
                    }
                }
                if(!flag) break;
            }

            return perM;
        }   


        
    void dfs(int i,int j,vector<vector<int>>&val)
    {
    
        if(i<0 || j<0 || i>=n || j>=m)  
        {
            return ;
        }

        if(val[i][j]==0) return ;
        if(vis[i][j]) return ;

        vis[i][j] =1;



        if(i+1>=n || val[i+1][j] == 0 ) perM++;
        if(j+1>=m || val[i][j+1] == 0 ) perM++;
        if(i-1<0  || val[i-1][j] == 0 ) perM++;
        if(j-1<0  || val[i][j-1] == 0 ) perM++;
        
        dfs(i+1,j,val) ;   
        dfs(i,j+1,val) ;   
        dfs(i-1,j,val) ;    
        dfs(i,j-1,val) ;   
    }

    };

    int main(void)
    {    
        Solution s;
        cin>>s.n>>s.m;

        for(int i=0;i<s.n;i++)
        {   
        vector<int> tmp; 
            for(int j=0;j<s.m;j++) 
            {   
                int x;
                cin>>x;
                tmp.push_back(x);
            }
        s.val.push_back(tmp) ;
        }

        

        cout<<s.islandPerimeter(s.val)<<endl;
        
    

        return 0;
    }



*/