
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m;
    cin>>n>>m;
    vector<long long> labs (n+10,0);
    vector<long long>task(m+10,0);

    vector<pair<long long,long long>> consecutive  ;

    for(int i=1;i<=n;i++)
    {

        cin>>labs[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>task[i];
    }

  //Here is the error . I used int instead of  long long. 

     long long x=0;    
     long long y=0;
    for(int i=1;i<=n;i++)
    {
        x=y;
        x++;
        y+=labs[i];
        consecutive.push_back({x,y});

    }



    long long t=m;
    long long labNum,taskNum;
    long long taskOnCount=1;
    while(t--)
    {
        labNum=1;
        for(int i=0;i<n;i++)
        {

            if( consecutive[i].first <=task[taskOnCount] &&  consecutive[i].second>=task[taskOnCount] )
            {
                taskNum=task[taskOnCount]-  ( consecutive[i].first-1)  ;
                cout<<labNum<<" "<<taskNum<<endl;

                break;
            }
           labNum++;

        }
        taskOnCount++;
       // cout<<"YY "<<t<<endl;
    }

}

/*

  3 6
  10 15 12
  1 9 12 23 26 37

  2 3
  5 10000000000
  5 6 9999999999


*/
