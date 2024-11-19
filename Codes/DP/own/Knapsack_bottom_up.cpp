#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

long long solution[100+10][N] ;

long long maxProfit(vector<int>&v,vector<long long>&w,int amount)
{
    int n=v.size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            if(i==0)
            {
                if(v[i]>j) solution[i][j]=0;
                else 
                  solution[i][j]=w[i];
            }
            else if( v[i]>j)
            {
                solution[i][j]=solution[i-1][j];

            }
            else
            {
                solution[i][j]= max( solution[i-1][j],w[i]+solution[i-1][j-v[i]] ); 
            }
        }
    }

    return solution[n-1][amount];


}


int main(void)
{   
      int n , amount;
      cin >> n >> amount;

      vector<int>v(n);
      vector<long long>w(n);

      for(int i=0 ;i<n;i++)
      {
         cin>>v[i]>>w[i] ;

      }

      cout<< maxProfit(v,w,amount);


    

    



    return 0;
}

/*  

        3 9

        3 30
        4 50
        5 60

*/