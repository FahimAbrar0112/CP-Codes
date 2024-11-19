#include<bits/stdc++.h>
using namespace std;


int main(int argc,char * argv[])
{   
    int t;
    cin >> t;
    while (t--)
    {
        
        string s;
        cin >> s;
        int len=s.size();
        //1
        if(s[0]=='a'&&s[len-1]=='a')
        {   
            string tmp;
            for(int i=1;i<len-1 ;i++)
            {
                tmp.push_back(s[i]);
            }
            cout<<s[0]<<" "<<tmp<<" "<<s[len-1]<<endl;
        }
        //2
        else if(s[0]=='b'&&s[len-1]=='b')
        {
            string tmp;
            for(int i=1;i<len-1 ;i++)
            {
                tmp.push_back(s[i]);
            }
            cout<<s[0]<<" "<<tmp<<" "<<s[len-1]<<endl;
        }
        //3 4
        else if(s[0]=='a'&&s[len-1]=='b')
        {
            if(s[1]=='b')
            {
                string tmp;
                for(int i=1;i<len-1 ;i++)
                {
                    tmp.push_back(s[i]);
                }
                cout<<s[0]<<" "<<tmp<<" "<<s[len-1]<<endl;
            }
            if(s[1]=='a')
            {
                string tmp;
                for(int i=2;i<=len-1 ;i++)
                {
                    tmp.push_back(s[i]);
                }
                cout<<s[0]<<" "<<s[1]<<" "<<tmp<<endl;
            }
        }
        //5 
        else if(s[0]=='b'&&s[len-1]=='a')
        {
            string tmp;
           if(s[1]=='b')
           {
                for(int i=1;i<len-1 ;i++)
                {
                    tmp.push_back(s[i]);
                }
                cout<<s[0]<<" "<<tmp<<" "<<s[len-1]<<endl;
           } 
           if(s[1]=='a')
           {
                for(int i=2;i<=len-1 ;i++)
                {
                    tmp.push_back(s[i]);
                }
                cout<<s[0]<<" "<<s[1]<<" "<<tmp<<endl;
           } 
            
        }
        else
         cout<<": ("<<endl;
   }
        
    
    
    



    return 0;
}