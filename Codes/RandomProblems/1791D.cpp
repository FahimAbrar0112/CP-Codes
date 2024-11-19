#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;



int main(void)
{
      int t;
      cin >> t;

      while (t--)
      {
        int n;
        cin >> n;
        string s;
        cin >> s;

        map<char,int>m_forward;
        map<char,int>m_backward;
        vector<int> vforward,vbackward ;

        for(int i=0; i<n; i++)
        {
            m_forward[s[i]] ++;
            vforward.push_back(m_forward.size());
        }

        for(int i=n-1; i>=0; i--)
        {
            m_backward[s[i]] ++;
            vbackward.push_back(m_backward.size());
        }
        
         reverse(vbackward.begin(), vbackward.end());

        int ans=INT_MIN;

        for(int i=0; i<n-1; i++)
        {
            ans=max(ans, vforward[i]+vbackward[i+1]);
        }

        cout<<ans<<endl;
       
        // for(int i=0;i<n;i++)
        // {
        //     cout<<vforward[i]<<" ";
        // }

        // cout<<endl;

        // for(int i=0;i<n;i++)
        // {
        //     cout<<vbackward[i]<<" ";
        // }

         
         


       

        // cout<<endl<<ans<<endl;


      }






    return 0;
}


/*  

    1
    7
    abcabcd

    


*/