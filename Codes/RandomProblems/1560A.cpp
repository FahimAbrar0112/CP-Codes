#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int num[N];


int main(int argc,char * argv[])
{   
      int t;
      cin >> t; 

      int track=1; 
      for(int i=1;i<1e5;i++)
      {
        if(i%3!=0 &&  (i%10!=3))
        {
            num[track]=i;
            track++;
        }
      }

  

      while (t--)
      {
        int k;
        cin >> k;
        cout << num[k] << endl;


      }
    

    



    return 0;
}