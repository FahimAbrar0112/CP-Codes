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

         vector<int> v ;
         v.push_back(-1);
         int i=1,j=n*n;
         while(i<=j)
         {
            if(i==j)
            {
                v.push_back(i);
            }
            else
            {
                v.push_back(j);
                v.push_back(i);
            }
            i++;
            j--;
         }



        // for(int i=1;i<=n*n;i++)
        // {
        //     cout<<v[i]<<" ";

        // }

        int track=1;
        for(int i=1;i<=n;i++)
        {
            if(i%2!=0)
            {   
                int tmp=track;
                for(int j=track;j<tmp+n;j++)
                {
                    cout<<v[j]<<" ";
                    track++;
                }
                cout<<endl;
            }
            else
            {
                int tmp=track;
                for(int j=track+n-1;j>=tmp;j--)
                {
                    cout<<v[j]<<" ";
                    track++;
                }
                cout<<endl;
            }
        }

    }  
    

    



    return 0;
}