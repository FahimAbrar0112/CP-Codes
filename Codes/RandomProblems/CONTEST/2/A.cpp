#include<bits/stdc++.h>
using namespace std;



int main(void)
{   
    int t;
    cin >> t;

    while (t--)
    {
         int n;
         cin >> n;

         vector<int> v;
         int pos=0,neg=0 ;
         for(int i=1; i<=n; i++)
         {
            int x;
            cin >> x;
            v.push_back(x);
            if(x>0) pos++;
            else
                neg++;         
         }
         
         int ans;
         
         if(neg==0)
          ans=pos-4 ;
         else
         {
            bool flag =true;
            for(int i=1;i<=n-1;i++)
            {
                if(v[i-1]==-1 && v[i]==-1)
                {
                    flag = false;
                    break;
                }  
            }
            if(!flag) 
            {   
                neg-=2;
                pos+=2;
                ans =pos-neg ;
            }
            else
            {
                ans = pos-neg;
            }
         } 

         cout<<ans<<endl ;



    }  
    

    



    return 0;
}