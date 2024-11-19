#include<bits/stdc++.h>
using namespace std;



int main(int argc,char * argv[])
{   
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v;
        map<int,int> mp;

        for(int i=2;i*i<=n;i++) //Prime checking
        {
            if(n%i==0)  // divisible by prime number
            {
                while( n%i==0 ) //
                {
                    n/=i;
                    v.push_back(i);
                }
            }
        }


        if(n!=1 )
        {
            v.push_back(n);
        }
        
       

        int N = v.size();
        vector<bool> vis(N,false);
        int ans=0;
        for(int i=0;i<N;i++)
        {
            if(vis[i]) continue;
            int mul=v[i];
            int check = v[i];
            for(int j=i+1;j<N;j++)
            {
                if(vis[j] || v[j]==check) continue;
                mul*=v[j];
                check=v[j];
                vis[j]=true;
            }
            ans+=mul;


        }
        
        cout<<ans<<endl;

        


        

        



    }  
    

    



    return 0;
}