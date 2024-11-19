#include<bits/stdc++.h>
using namespace std;



bool cmp(int a,int b)
{
    return a>b;

}

int main(int argc,char * argv[])
{   
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=0;i<=n;i++)
    {
        v[i]=0;
    }

    
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }  
    sort(v.begin()+1,v.end(),cmp);

    int s1[n+10],s2[n+10];

    for(int i=0;i<=n+1;i++)
    {
        s1[i]=0;
        s2[i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        s1[i] = s1[i-1]+v[i] ;
    }
    
    for(int i=n;i>=1;i--)
    {
        s2[i]=s2[i+1]+v[i] ;
    }

    int ct=0;

    for(int i=1;i<=n;i++)
    {
        if(s1[i]<=s2[i])
         ct++;
        else
        { 

            if(s1[i-1]>s2[i])
             break;
            else
            {
                ct++;
                break; 
            } 
        }
         
    }
    cout<<ct;
    



    return 0;
}