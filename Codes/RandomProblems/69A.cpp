#include<bits/stdc++.h>
using namespace std;



int main(int argc,char * argv[])
{   
    int n;
    cin >> n;

    vector<int> v[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    
    int x,y,z;
    x=y=z=0;
    
        // x=v[0][0]+v[1][0]+v[2][0] ;
        // y=v[0][1]+v[1][1]+v[2][1] ;
        // z=v[0][2]+v[1][2]+v[2][2] ;

     for(int i=0;i<n;i++)
     {
        x+=v[i][0];
        y+=v[i][1];
        z+=v[i][2];
     }   
    
     if(x==0 && y==0 && z==0)
      cout<<"YES"<<endl;
     else
      cout<<"NO"<<endl; 
    



    return 0;
}