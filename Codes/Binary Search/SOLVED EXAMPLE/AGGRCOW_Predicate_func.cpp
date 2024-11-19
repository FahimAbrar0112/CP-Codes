#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,cows;
int positions[N];

bool canPlaceCow(int minDist)
{
    int lastPos=-1;
    int cows_ct=cows;
    for(int i=0;i<n;i++)
    {
        if( positions[i]-lastPos>=minDist || lastPos==-1)
        {
            cows_ct--;
            lastPos=positions[i];
        }
        if(cows_ct == 0 ) break;
    }
    return cows_ct == 0;

}


int main()
{   
      int t;
      cin >> t;
      while (t--)
      {
        cin>>n>>cows;
        for(int i=0;i<n;i++)
        {
            cin>>positions[i];
        }
        
        sort(positions,positions+n);
        //T T T T T T F F F F F F F F 
        int lo=0,hi=1e9+10;
        while(hi-lo>1)
        {
            int mid=(lo+hi)/2;
            if(canPlaceCow(mid))
            {
                lo=mid;
            }
            else
            {
                hi=mid-1;
            }

        }

        if(canPlaceCow(hi))
         cout<<hi<<endl;
        else
         cout<<lo<<endl; 


     }
    

    



    return 0;
}




/** 

        1
        5 3
        1 
        2
        8
        4
        9

*/