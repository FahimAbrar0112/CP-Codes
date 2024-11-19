#include<bits/stdc++.h>
using namespace std;



int main(int argc,char * argv[])
{   
    int t;
    cin >> t;
    while(t--)
    {
        int n,s,r , a1 ;

        cin >> n>>s>>r;

       int mx=s-r;

        int N=n-1;
        // 3 5

        vector<int> v(N,0);

        int step_val= r/N;

        for(int i=0;i<N;i++)
        {
            v[i]=step_val;
        }    

        int sum=r-step_val*N;

        bool flag=true;
        int i=0;
        while(1)
        {   
            if(sum==0) break;
            v[i]++;
            sum--;
            i = (i+1)%N;
        }

        cout<<mx<<" ";
        for(int i=0;i<N;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
       

    }  
    

    



    return 0;
}