#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

bool isPossible[110][N];

vector<int> moneySum(vector<int> &num,int sum)
{
     int n = num.size();
     for (int i = 0; i < n;i++)
     {
         for(int j = 0; j <=sum; j++)
         {  
           
            //1st ROW: i=0
             if(i==0 && j==0)
             {
                isPossible[i][j] = 1;
                
             }
             else if(i==0 && j-num[i]==0) isPossible[i][j]=1;
             else if(i==0)
             {
                isPossible[i][j]=0;
             }
             
           //Other ROWS:
             else if(num[i]>j)
             {  if(i>1) 
                isPossible[i][j]=isPossible[i-1][j];
             }
             else 
             {  if(j-num[i] >=0)
                isPossible[i][j]=isPossible[i-1][j] |  isPossible[i-1][j-num[i]];
             }
             
             cout<<isPossible[i][j]<<" ";

         }
        cout<<endl; 
     }

   vector<int> ans;
    for(int  j=1;j<=sum;j++ )
    {
        if(isPossible[n-1][j]) ans.push_back(j);
    }
  return ans;

}


int main(void)
{   
    int n;
    cin >> n;
    vector<int>num(n);
    int sum=0;
    for (int i=0; i<n; i++)
    {
        cin >> num[i];
        sum+=num[i];
    }  


    vector<int> ans;
    ans=moneySum(num,sum);

     for(auto  x:ans)
     {
        cout<<x<<" ";
     }

    



    return 0;
}
/*  

    4
    4 2 5 2

*/