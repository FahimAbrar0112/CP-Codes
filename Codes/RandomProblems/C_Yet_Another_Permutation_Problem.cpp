#include<bits/stdc++.h>
using namespace std;
 
 

int main(void)
{
    int t;
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;

        vector<bool> check(1e5+10,0);

        vector<int> ans;
        ans.push_back(1);
        check[1]=1;


        for(int i=2;i<=n;i++)
        {
            int x=i;
           

            while(x<=n)
            {
                 if(check[x])
                  break;
                 ans.push_back(x);
                 check[x]=1;
                 x+=x;

            }
        }   


        for(auto x:ans)
        {
            cout<<x<<" ";
        }  
        cout<<endl;
    }
    


    return 0;
}

/*  

1 7

*/