#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;

/*
    There are n different type of fruits present in a market.
    Some number of people m go to market and buy everyone different type of fruits.
    find the common fruit they have bought from the market.

    4 3
    apple  banana mango lichi 

    4
    apple banana mango lichi
    3
    lichi  banana mango
    4
    apple mango banana lichi


    ans:  banana


*/

void setBit(int &n,int i)
{
    n |=(1<<i);
}

void extractIndex(vector<int>&index,int ans)
{
    for(int i=31;i>=0;i--)
    {
        if( (ans>>i) & 1){
         index.push_back(i);

        } 
    }
}

void printBinary(int n)
{
    for(int i=31;i>=0;i--)
    {
        cout<< ( ( n>>i) & 1 );
    }
    cout<<endl;
}


int main(void)
{
    int n,m;
    cin>>n>>m;
    vector<string> fruits(n);
    unordered_map<string,int> mp;

    for(int i=0;i<n;i++)
    {   
        
        cin>>fruits[i];
        mp[fruits[i]] = i;
    }

    vector<int>v(m,0);
    for(int i=0;i<m;i++)
    {
        int fruit_kinse;
        cin>>fruit_kinse;

        for(int j=0;j<fruit_kinse;j++)
        {
            string tmp;
            cin>>tmp;
            setBit(v[i],mp[tmp]);
        }
        
    }   

   

    int ans=~0;
    //printBinary(ans);

    for(int i=0;i<m;i++)
    {
        ans = (ans &  v[i]);
        //printBinary(ans &  v[i]);
    }

    vector<int>index;

    extractIndex(index,ans);
    for(auto val:index)
    {
        cout<<fruits[val]<<endl;
    }

    //printBinary(ans);


    


    return 0;
}