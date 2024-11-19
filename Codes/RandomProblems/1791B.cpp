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
        int x=0,y=0;
        
        bool flag=1;
        for(int i=0;i<n;i++)
        {
            
            
            
                if(s[i]=='U') y++;
                if(s[i]=='D') y--;
                if(s[i]=='R') x++;
                if(s[i]=='L') x--;

                if(x==1 && y==1) 
            {
                cout<<"YES"<<endl;
                flag=false;
                break;
            }
            
        }

        if(flag)
        {
            cout<<"NO"<<endl;
        }

    }
    



    return 0;
}