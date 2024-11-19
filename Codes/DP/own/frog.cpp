#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int cost[N];

int COST_TAKE(vector<int> val)
{
    cost[0] = 0;
    cost[1] = abs(val[0]-val[1]);
    int n=val.size();
    for(int i=2;i<n;i++)
    {
         cost[i]= min( cost[i-2]+abs(val[i]-val[i-2]) ,  cost[i-1]+abs(val[i]-val[i-1])  );

    }

   return cost[n-1]; 
}

int main(void)
{   
      
    int n;
    cin >> n;

    vector<int> val(n);
    for(int i=0; i<n; i++)
    {
        cin >> val[i];
    }

    cout<<COST_TAKE(val);


    



    return 0;
}
/*  
    4
    10 30 40 20 
    
*/