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

        vector<int> v(n+10,0);
        int odd_ct=0,even_ct=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin >> x;
            v[i]=x;
            

            if(x%2==0) even_ct++;
            else odd_ct++;
        }

        bool flag=true;

        if(odd_ct>=1)
        {
            if(even_ct>=2)
            {   
                flag=false;
                cout<<"YES"<<endl;
                int odd=0,even=0;

                for(int i=1;i<=n;i++)
                {   
                     if(v[i]%2!=0 && odd<1) 
                     {
                         cout<<i<<" ";
                         odd++;
                     }
                     else if(v[i]%2==0 && even<2)
                     {
                        cout<<i<<" ";
                        even++;
                     }
                    
                    if(odd==1 && even==2)
                    {
                        break;
                    }
                }
                cout<<endl;
            }
            else if(odd_ct>=3)
            {   
                 flag=false;
                 cout<<"YES"<<endl;
                 
                 int odd=0;
                 for(int i=1;i<=n;i++)
                 {
                    if(v[i]%2!=0 && odd<=3)
                    {
                        cout<<i<<" ";
                        odd++;
                    }
                    if(odd==3) break;
                 }
                 cout<<endl;
            }
            

        }
        if(flag==true)
        cout<<"NO"<<endl;
    }  
    

    



    return 0;
}