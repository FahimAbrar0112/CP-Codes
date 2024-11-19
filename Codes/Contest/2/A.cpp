#include<bits/stdc++.h>
using namespace std;

// 3.141592653589793238462643383279

int main(int argc,char * argv[])
{   
      int t;
      cin >> t;
      while(t--)
      {
         string s;
         cin >> s;

         string pi = "3141592653589793238462643383279";

         bool flag=true;
         int ct=0;

         for(int i=0;i<s.size();i++)
         {
            if(s[i]==pi[i])
            {
                ct++;
            }
            else
            {
                flag=false;
                break;
            }
         }

         cout<<ct<<endl;


      }
    
    //  string pi = "3141592653589793238462643383279";
    //  cout<<pi.size()<<endl;

    



    return 0;
}