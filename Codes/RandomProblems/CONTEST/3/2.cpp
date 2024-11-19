#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;



int main(void)
{   
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        multiset<int>s;
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin >> x;
            if(x!=0)
            {
              s.insert(x);
            }
            else
            {  
              if(s.size()==0) 
              {
                //cout<<s.size()<<endl;
                continue;
              }
              else
              {
                auto it=s.end();
                it--;
                sum+= (*it);
                //cout<<sum<<endl;
                s.erase(it);
              }
              


            }
            
        }
        cout<<sum<<endl;

    }  
    

    



    return 0;
}