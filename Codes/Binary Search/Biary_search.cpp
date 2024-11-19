#include<bits/stdc++.h>
using namespace std;


void Binary_search(vector<int>&v , int to_find)
{
    int lo=0,hi=v.size()-1;
    while(hi-lo>1)
    {
        int mid = (hi+lo)/2;
        //
        if(v[mid]<to_find)  
          lo=mid+1;   
        else
          hi=mid;  
    }

    if(v[lo]==to_find) 
     cout<<lo<<" "<<v[lo]<<endl;
    else if(v[hi]==to_find)
     cout<<hi<<" "<<v[hi]<<endl;
    else  
      cout<<"Not FOUND!"<<endl;

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

    Binary_search(v,target);


    



    return 0;
}


/***    
        10 
        1 5 7 8 9 12 14 16 20  45
        12




        10 
        1 5 7 8 9 12 14 16 20  45
        10



        10 
        1 5 7 8 9 12 14 16 20  45
        45


***/