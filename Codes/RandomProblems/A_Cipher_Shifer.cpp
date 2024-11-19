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
        string s;
        cin>>s;

        string encryp;
        char x=s[0];
        for(int i=1;i<n;i++)
        {
            if(x==s[i])
            {
                encryp.push_back(x);
                i++;
                x=s[i];
            }
        }
        cout<<encryp<<endl;
        encryp.clear();


    }


    return 0;
}