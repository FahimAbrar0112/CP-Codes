#include<bits/stdc++.h>
using namespace std;

int Lower_Bound(vector<int>&v , int to_find)
{
    int lo=0,hi=v.size()-1;
    while(hi-lo>0)
    {
        int mid = (hi+lo)/2;
        //
        if(v[mid]<to_find)  
          lo=mid+1;   
        else
          hi=mid;  
    }

    if(v[lo]>=to_find) 
     return lo;
    else if(v[hi]>=to_find)
    return hi;
    else  
    return -1;

}




int main(int argc,char * argv[])
{   
    int n;
    cin>>n;

    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    int target;
    cout<<endl<<"Target: ";
    cin>>target;
    
    int ind=Lower_Bound(v,target);
    cout<<ind<<" "<< (ind!=-1? v[ind]:-1)<<endl;
    



    return 0;
}