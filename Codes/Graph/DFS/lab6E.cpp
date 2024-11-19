
#include<bits/stdc++.h>
using namespace std;

const int MODULO = 1e9+7;

int dp[1010][1010];

int floodfill(int i,int j,vector<vector<char> >&image )
{
    int n=image.size();
    int m=image[0].size();

   // cout<<n<<" "<<m<<endl;

    if(i<0 || j<0) return 0;
    if(i>=n || j>=m) return 0;
    if(image[i][j]=='#') return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==n-1 && j==m-1 && image[i][j]=='.') return 1;
    
    
    
     
    //4 Sides:
    //floodfill(i-1,j,image);
    dp[i][j] = floodfill(i+1,j,image);
   // floodfill(i,j-1,image);
    dp[i][j]= (dp[i][j]+ floodfill(i,j+1,image) ) % MODULO;
    //4 Corners
    // floodfill(i-1,j-1,initialColor,newColor,image);
    // floodfill(i-1,j+1,initialColor,newColor,image);
    // floodfill(i+1,j-1,initialColor,newColor,image);
    // floodfill(i+1,j+1,initialColor,newColor,image);
  return dp[i][j];  
}
 

int main(int argc,char * argv[])
{   
      //cout<<"ENTER N size of MAT:" <<endl;
     
     // cout<<"Enter elements: "<<endl;
     memset(dp,-1,sizeof(dp));
      int n,m;
      cin >> n>>m;
      vector<vector<char>> image;
      for(int i=1;i<=n;i++)
      {
        vector<char>tmp;
        for(int j=1;j<=m;j++)
        {
            char x;
            cin >> x;
            tmp.push_back(x);
        }
        image.push_back(tmp);
      }
       //cout<<"Enter rowNo colNo & newColor:"<<endl;
       
      int ans=floodfill(0,0,image);
       
      cout<<ans<<endl;

    //   for(int i=0;i<n;i++)
    //   {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<image[i][j]<<" ";
    //     }
    //    cout<<endl; 
    //   }  



    return 0;
}

/*
    3
    1 0 1
    0 1 0
    1 0 1

    1 1 5
    
*/