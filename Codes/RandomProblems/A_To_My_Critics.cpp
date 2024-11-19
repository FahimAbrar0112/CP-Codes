#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;



int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int arr[3];
        for(int i=0;i<3;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+3);
        if((arr[2]+arr[1]) >=10)
         cout<<"YES"<<endl;
        else
         cout<<"NO"<<endl; 
    }


    return 0;
}