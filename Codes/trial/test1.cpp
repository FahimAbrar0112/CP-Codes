#include<bits/stdc++.h>
using namespace std;



int main(int argc,char * argv[])
{   
      
    int n,m;
    cin >> n >> m;

    vector<long long> v ;
    for(int i=0;i<n;i++)
    {
        long long tmp;
        cin >> tmp;
        v.push_back(tmp%m);
    }
    sort(v.begin(),v.end());
    int q;
    cin >> q ;

    while(q--)
    {   
        int i=0;
        long long x;
        cin >> x ;
        x=x%m;
        // 
        int boundary =  m-x-1;
        auto it = upper_bound(v.begin(),v.end(), boundary);
        if(it!=v.begin())
        {
            it--;
        }


         cout<<max((v[n-1]+x)%m, (*it+x)%m )<<endl;
    }


    



    return 0;
}