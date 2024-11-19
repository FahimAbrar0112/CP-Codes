#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;



int main(void)
{   
    int t;
    cin >> t;
     string s="codeforces" ;
    // map<string,int> mp;
    // for(int i=0; i<s.size(); i++)
    // {
    //     mp[ s[i] ] = 1 ;
    // }


    while (t--)
    {
         string  x;
         cin >> x;
         
        //  auto it=mp.find(x,0);
        //  if(it!=mp.end())
        //  {
        //     cout<<"YES"<<endl;

        //  }
        //  else
        //  {
        //     cout<<"NO"<<endl;
        //  }
         
         bool flag=true;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==x[0])
            {
                cout<<"YES"<<endl;
                flag=false;
                break;
            }
               
        }

        if(flag) cout<<"NO"<<endl;
    }  
    

    



    return 0;
}