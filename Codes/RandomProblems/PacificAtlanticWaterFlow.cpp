#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;

bool vis1[N][N];
bool vis2[N][N];
vector<vector<int>> val;
vector<vector<int>> ans ;
int n,m;

void dfs1(int i,int j)
{
    if(i< 0 || j<0 || i>=n || j>=m) return;
    if(vis1[i][j] ) return ;
    
    vis1[i][j]=1;

    if(!(i+1>=n)  && val[i][j]<=val[i+1][j])
    {
        dfs1(i+1,j);
    }
    if(!(j+1>=m)  && val[i][j]<=val[i][j+1])
    {
        dfs1(i,j+1);
    }
    if(!(i-1<0)  && val[i][j]<=val[i-1][j])
    {
        dfs1(i-1,j);
    }
    if(!(j-1<0 ) && val[i][j]<=val[i][j-1])
    {
        dfs1(i,j-1);
    }

}

void dfs2(int i,int j)
{
    if(i< 0 || j<0 || i>=n || j>=m) return;
    if(vis2[i][j] ) return ;
    
    vis2[i][j]=1;

    if(!(i+1>=n)  && val[i][j]<=val[i+1][j])
    {
        dfs2(i+1,j);
    }
    if(!(j+1>=m)  && val[i][j]<=val[i][j+1])
    {
        dfs2(i,j+1);
    }
    if(!(i-1<0)  && val[i][j]<=val[i-1][j])
    {
        dfs2(i-1,j);
    }
    if(!(j-1<0 ) && val[i][j]<=val[i][j-1])
    {
        dfs2(i,j-1);
    }

}

vector<vector<int>> pacificAtlantic()
{
    for(int j=0;j<m;j++)
    {
        dfs1(0,j);
    }

    for(int i=0;i<n;i++)
    {
        dfs1(i,0);
    }


    for(int j=0;j<m;j++)
    {
        dfs2(n-1,j);
    }

    for(int i=0;i<n;i++)
    {
        dfs2(i,m-1);
    }

    for(int i=0;i<n;i++)
    {   
      
        for(int j=0;j<m;j++)
        {  
            vector<int>tmp; 
            if(vis1[i][j]==1 && vis2[i][j]==1)
            {
                tmp.push_back(i);
                tmp.push_back(j);
                ans.push_back(tmp);  
            }
        }
      
    }
  return ans;  

}



int main(void)
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
       val.push_back(tmp); 
    }

    vector<vector<int>> ANS = pacificAtlantic();

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<vis1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //  cout<<endl;
    //  cout<<endl;

    
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<vis2[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //  cout<<endl;
    //  cout<<endl;



    for(auto elm: ANS)
    {
        cout<<elm[0]<<" "<<elm[1]<<endl;
    }
      


    return 0;
}

/*

    5 5 
    1 2 2 3 5
    3 2 3 4 4
    2 4 5 3 1
    6 7 1 4 5
    5 1 1 2 4

    1 1 
    1


    2 2 
    2 1 
    1 2


    // 0 0
       0 1
       1 0
       1 1

*/





/*

  #include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;



class Solution 
{
    public:
      
        bool vis1[N][N];
        bool vis2[N][N];
        vector<vector<int>> val;
        vector<vector<int>> ans ;
        int n,m;
        
    void dfs1(int i,int j,vector<vector<int>> &val)
    {
        if(i< 0 || j<0 || i>=n || j>=m) return;
        if(vis1[i][j] ) return ;
        
        vis1[i][j]=1;

        if(!(i+1>=n)  && val[i][j]<=val[i+1][j])
        {
            dfs1(i+1,j,val);
        }
        if(!(j+1>=m)  && val[i][j]<=val[i][j+1])
        {
            dfs1(i,j+1,val);
        }
        if(!(i-1<0)  && val[i][j]<=val[i-1][j])
        {
            dfs1(i-1,j,val);
        }
        if(!(j-1<0 ) && val[i][j]<=val[i][j-1])
        {
            dfs1(i,j-1,val);
        }

    }

    void dfs2(int i,int j,vector<vector<int>>&val)
    {
        if(i< 0 || j<0 || i>=n || j>=m) return;
        if(vis2[i][j] ) return ;
        
        vis2[i][j]=1;

        if(!(i+1>=n)  && val[i][j]<=val[i+1][j])
        {
            dfs2(i+1,j,val);
        }
        if(!(j+1>=m)  && val[i][j]<=val[i][j+1])
        {
            dfs2(i,j+1,val);
        }
        if(!(i-1<0)  && val[i][j]<=val[i-1][j])
        {
            dfs2(i-1,j,val);
        }
        if(!(j-1<0 ) && val[i][j]<=val[i][j-1])
        {
            dfs2(i,j-1,val);
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>&val)
    {   
        n=val.size();
        m=val[0].size();

        for(int j=0;j<m;j++)
        {
            dfs1(0,j,val);
        }

        for(int i=0;i<n;i++)
        {
            dfs1(i,0,val);
        }


        for(int j=0;j<m;j++)
        {
            dfs2(n-1,j,val);
        }

        for(int i=0;i<n;i++)
        {
            dfs2(i,m-1,val);
        }

        for(int i=0;i<n;i++)
        {   
        
            for(int j=0;j<m;j++)
            {  
                vector<int>tmp; 
                if(vis1[i][j]==1 && vis2[i][j]==1)
                {
                    tmp.push_back(i);
                    tmp.push_back(j);
                    ans.push_back(tmp);  
                }
            }
        
        }
    return ans;  

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
       s.val.push_back(tmp); 
    }

    vector<vector<int>> ANS = s.pacificAtlantic(s.val);

  


    for(auto elm: ANS)
    {
        cout<<elm[0]<<" "<<elm[1]<<endl;
    }
      


    return 0;
}

/*

    5 5 
    1 2 2 3 5
    3 2 3 4 4
    2 4 5 3 1
    6 7 1 4 5
    5 1 1 2 4

    1 1 
    1

*/





*/