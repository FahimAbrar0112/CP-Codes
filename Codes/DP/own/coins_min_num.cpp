#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const long long INF=1e9+10;

//vector<vector<int>> solution (110,vector<int>(3000,0)) ;



int min_coin(vector<int> & coin,int amount )
{   
    int n = coin.size();
    int solution[n+1][amount+1];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=amount;j++)
        {   
            if(i==0)
            {
                if(j%coin[i] == 0)
                 solution[i][j] = j/coin[i];
                else
                 solution[i][j] = INF;
                  
            }
            else if(coin[i]> j)
            {
                solution[i][j] = solution[i-1][j];
            }
            else
            {
                solution[i][j] = min( solution[i-1][j],1+solution[i][j - coin[i]]) ;
            }
        }
    }

   return solution[n-1][amount]==INF? -1: solution[n-1][amount]; 


}


int main(void)
{   
      
    int n,amount;
    cin >> n>>amount;;
    vector<int>coin(n);

    for(int i=0;i<n;i++)
    {
        cin >> coin[i];
    }

    cout<<min_coin(coin,amount);

    



    return 0;
}


/*

        4 10
        2 5 6 9


        3 11
        1 2 5



*/