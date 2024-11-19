#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;
int solution[305][N];

int waysPossible(vector<int>&coins,int amount )
{
    int n=coins.size();
    //memset(solution,0,sizeof(solution));


    
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<=amount;j++)
        {
               if(i==0 && j==0) 
                solution[i][j] = 1;
               else if(coins[i]>j) 
                {
                    if(i==0)
                    {
                        solution[i][j] =0;
                    }
                    else
                    {
                        solution[i][j]=solution[i-1][j];
                    }
                }
             else 
              { 
                if(i==0)
                {
                    if(j%coins[i] == 0) 
                     solution[i][j] =1;
                    else
                     solution[i][j]=0; 

                }

                if(i!=0)
                 solution[i][j]= solution[i-1][j]+solution[i][j-coins[i]] ;
              }
               

        }
       
    }

    return solution[n-1][amount];

}


int main(void)
{   
      
    int n, amount;
    cin >> n>>amount;
    vector<int>coins(n,0);
    for(int i=0; i<n; i++)
    {
        cin>>coins[i];
    }

    cout<<waysPossible(coins,amount)<<endl;

   

    



    return 0;
}

/*  
    3 8
    1 3 5
    // 5

    4 15
    2 3 5 10

    // 9



*/