#include<bits/stdc++.h>
using namespace std;



int main(int argc,char * argv[])
{   
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);

        for(int i=0; i<n; i++)
        {
            cin >> v[i];
        }

       int ct=0;
        
        for(int i=1;i<n;i++)
        {   

            //O O
            if(v[i]%2!=0 && v[i-1]%2!=0)
            {
                ct++;

                //cout<<">>"<<v[i]<<" "<<v[i-1]<<endl;
            }
            else if(v[i]%2==0 && v[i-1]%2==0)
            {
                ct++;
                //cout<<"<<"<<v[i]<<" "<<v[i-1]<<endl;
            }

        }

        cout<<ct<<endl;




    }  
    

    



    return 0;
}