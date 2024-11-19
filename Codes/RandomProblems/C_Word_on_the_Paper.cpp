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
        string s;
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
            {
                char x;
                cin>>x;
                if(x=='.')
                {

                }
                else
                 s.push_back(x);
            }
        }
        cout<<s<<endl;
    }
    


    return 0;
}