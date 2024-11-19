#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;



int main(void)
{
    
    int t;
    cin>>t;
    while (t--) 
    {
        int n;
        cin>>n;
        vector<int>v;
        int track=-1;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;

            if(i==1)
            {
                v.push_back(x);
                track++;
            }
            else
            {
                if(x>=v[track])
                {
                    v.push_back(x);
                    track++;
                }
                else
                {
                    v.push_back(x);
                    v.push_back(x);
                    track+=2;
                }
            }

            
        }

        cout<<v.size()<<endl;
        for(auto  x:v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }


    
    

    return 0;
}