#include<bits/stdc++.h>
using namespace std;



int main(int argc,char * argv[])
{   
    int n;
    cin >> n;

    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }  

    vector<int>valied;
    int prev=-1,curr;
    int one=0,two=0;

    for(int i=0;i<n;i++)
    {   
        curr=v[i];
        if( curr==prev || prev==-1 )
        {
            prev=curr;
            if(curr==1)
             one++;
            else
             two++; 
        }
        else
        {
            if(one!=0) valied.push_back(one);
            else if(two!=0) valied.push_back(two);

            one=0;
            two=0;

            prev=curr;
            if(curr==1)
             one++;
            else
             two++;
        }
    }

    if(one!=0) valied.push_back(one);
    else if(two!=0) valied.push_back(two);

    int val,max=-1;
    for(int i=0;i<valied.size()-1;i++)
    {
        val=min(valied[i],valied[i+1]);
        if(max<val) max=val;
    }

    max*=2;

    cout<<max<<endl;
    

    


    return 0;
}