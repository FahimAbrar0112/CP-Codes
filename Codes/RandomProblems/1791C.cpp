#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int foo()
{
        int n;
        string s;

        cin>>n;
        cin>>s;

        int ct=n;

        if(n==1)  return 1;
        else
        {
            int len = n/2; 
            int first=0,last=n-1;

            for(int i=1; i<=len; i++)
            {
                if( (s[first]=='0' && s[last]=='1') || (s[first]=='1' && s[last]=='0'))
                {
                    ct-=2;
                    first++;
                    last--;
                }
                else
                {
                    break;
                }
            }
        }
      return ct;  
}

int main(void)
{   
    int t;
    cin >> t;
    while (t--)
    {
        
     cout<<foo()<<endl;
     
    }  
    
    



    return 0;
}