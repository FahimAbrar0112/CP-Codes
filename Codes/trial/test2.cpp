#include<bits/stdc++.h>
using namespace std;



int main(int argc,char * argv[])
{   
    // int t;
    // cin>>t;

    // while(t--)
    // {
        int N,x;
        cin>>N>>x;
        vector<int> v(N);
        for(int i=0;i<N;i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int count = 0;

        int i=0;
        while(x>0)
        {
            if(x>=v[i])
            {
                x-=v[i];
                count++;
            }
            else
            {
                break;
            }
            i++;
        }
        cout<<count<<endl;


   // }  
    

    



    return 0;
}

/*
        5 10
        8 5 4 3 2


*/