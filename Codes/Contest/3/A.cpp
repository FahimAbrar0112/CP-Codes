#include<bits/stdc++.h>
using namespace std;

const int N=200;
const int INF = INT_MAX;



int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int>a,b,c;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a.push_back(x);
        }

         int x= a[0];
        for(int i=1;i<n;i++)
        {
           if(x<a[i])
            x=a[i];
        }

       // cout<<x<<" uu"<<endl;

        for(int i=0;i<n;i++)
        {
           if(x==a[i])
            {
                c.push_back(x);
            }
           else
            b.push_back(a[i]); 
        }

        
        if(b.size()==0 || c.size()==0)
          cout<< -1<<endl;
       else
       {    
            
            cout<<b.size()<<" "<<c.size()<<endl;
            for(auto x:b) cout<<x<<" ";
            cout<<endl;
            for(auto x:c) cout<<x<<" ";
            cout<<endl;
       }  

        

        

          

 
         

        
        


    }
    


    return 0;
}
