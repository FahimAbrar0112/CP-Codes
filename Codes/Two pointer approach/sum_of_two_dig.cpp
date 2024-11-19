#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;

/*

    5 3 9 2 1

    can sum of 2 num be 8?



*/


int main(void)
{
    int n,target;
    cin>>n>>target;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int i=0,j=n-1;
    bool flag=false;
    while(i<j)
    {

        if(v[i]+v[j]==target)
        {
            //cout<<"yy"<<endl;
            flag=true;
            break;

        }
        else if(v[i]+v[j] < target)
         i++;
        else 
         j--; 
    }

    if(flag)
     cout<<"possible"<<endl;
    else
     cout<<"not possible"<<endl; 


    return 0;
}

/*

5 8
5 3 9 2 1


*/