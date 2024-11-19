#include<bits/stdc++.h>
using namespace std;



int main(int argc,char * argv[])
{   
    int n;
    cin >> n;

    //vector<int> v(n+10);
    vector<int>preSUm(n+1);

    for(int i = 1; i <=n; i++)
    {
        int x;
        cin>>x;

        preSUm[i]=preSUm[i-1]+x ;

    }
   
    int m;
    cin>>m;

    while(m--)
    {
        int k;
        cin>>k;

        auto it = lower_bound(preSUm.begin(),preSUm.end(),k);
        cout<<it-preSUm.begin()  <<endl;

    }
    
 

    



    return 0;
}