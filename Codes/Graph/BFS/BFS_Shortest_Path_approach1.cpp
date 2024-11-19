#include<bits/stdc++.h>
using namespace std;


// BFS can work to find shortest path
// Condition all edge must have same weight.
//OR EDGE can't have any weight.

const int N = 1e5+10;

bool vis[8][8];
int level[8][8];

int getX(string s)
{
    return s[0]-'a';
}

int getY(string s)
{
    return s[1]-'1';
}

vector<pair<int,int>> movements = {     
                                        {-1,2},{1,2},
                                        {-1,-2},{1,-2},
                                        {-2,1},{-2,-1},
                                        {2,1},{2,-1}
                                  };

bool isValied(int x  ,int y)
{
    return x>=0 && y>=0 && x<8 && y<8 ;
}


int bfs(string source,string dest)
{
    int sourceX=getX(source);
    int sourceY=getY(source); 
    int destX=getX(dest);
    int destY=getY(dest);
    
    queue<pair<int,int> >q;
    q.push({sourceX,sourceY});
    vis[sourceX][sourceY] = 1;

    while(!q.empty()) 
    {
        pair<int,int>v = q.front();
        int x=v.first,y=v.second;
        q.pop();
        for(auto movement : movements)
        {
            int childX=movement.first+x;
            int childY=movement.second+y;

            if(!isValied(childX,childY)) continue;
            if(!vis[childX][childY])
            {
                q.push({childX,childY});
                level[childX][childY]=level[x][y]+1;
                vis[childX][childY]=1;
            }
        }
    }
    return level[destX][destY];

}

void reset()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            level[i][j]=0;
            vis[i][j]=0;
        }
    }
}

int main(int argc,char * argv[])
{   
      int n;
      cin >> n;
      while (n--)
      {
        string s1,s2;
        cin >> s1 >> s2;
        cout<<bfs(s1,s2)<<endl;
        reset(); 
      }
    

    



    return 0;
}


/*  
    
            3
        a1 h8
        a1 c2
        h8 c3

*/