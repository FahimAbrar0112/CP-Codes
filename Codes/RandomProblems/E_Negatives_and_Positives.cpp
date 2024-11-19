#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;



int main(void)
{   
      int  t;
      cin >> t;
      while(t--)
      {
        int n;
        cin >> n;

        int neg=0;
        long long sum=0;
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            if(x<0) 
            {
                neg++;
                sum+= (-x);
                v.push_back(-x);
            
            }
            else
            {
                sum+=x;
                v.push_back(x);
            }

        }

        sort(v.begin(), v.end());
        int ans;
        if(neg%2==0)
        {
            cout<<sum<<endl;
        }
        else
        {
            cout<<sum-2*v[0]<<endl;
        }
         
        // cout<<ans <<endl; 


      }
    

    



    return 0;
}