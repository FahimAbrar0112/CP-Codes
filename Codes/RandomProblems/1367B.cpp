#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;



int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int even=0,odd=0,fine=0;

        for(int i=0;i<n;i++)
        {
             int x;
             cin>>x;
             if(i%2==0)
             {
                if(x%2!=0)
                {
                     even++;
                }
                 
             }
             else
             {
                if(x%2==0)
                {
                    odd++;
                }
             }
        }

        if(even==odd)
         cout<<even<<endl;
        else
         cout<<-1<<endl; 


    }


    return 0;
}