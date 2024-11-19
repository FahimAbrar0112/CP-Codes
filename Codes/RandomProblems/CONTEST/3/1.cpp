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

        string s;
        cin >> s;
        bool flag=false;

        if(n<4)
        {
            flag=true;

        }
        else
        {
            for(int i=0; i<n; i++)
            {
                s[i]=tolower(s[i]);
            }
            //cout<<s;
            char valied[]={'m','e','o','w'};
            int order=0;

        

            for(int i=0; i<n; )
            {
                if(order>3  )
                {
                    flag=true;
                    break;
                }

                if(s[i]==valied[order])
                {
                    s[i]='#';
                   // cout<<s[i];
                    i++;
                }
                else
                {
                    order++;
                   // cout<<order<<" ";
                }
            }
            // cout<<endl;
            // cout<<order<<" ";
            // cout<<s<<endl;

            for(int i=0; i<n; i++)
            {
                if(flag)
                break;
                else
                {
                    if(s[i]!='#')
                    {
                        flag=true;
                        break;
                    }
                } 
            }
            if(order != 3) flag = true;
            //cout<<order<<endl;
        }

        


        if(flag)
         cout<<"NO"<<endl;
        else
         cout<<"YES"<<endl;


    }  
    

    



    return 0;
}