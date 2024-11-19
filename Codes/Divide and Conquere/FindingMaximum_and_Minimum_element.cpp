#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;
// https://www.youtube.com/watch?v=GVFXYrMRqFw

void DAC(vector<int> &v ,int i ,int j, int &max,int &min)  // O(N) => O(1.5N)-2
{ 
    int mid;
    if(i==j)
     max=min=v[i];
    else if(i==j-1)
    {
        if(v[i]<v[j])
        {
            max = v[j];
            min = v[i];
        } 
        else
        {
            max = v[i];
            min = v[j];
        }
    }
    else
    {
        mid = (i+j)/2;
        int max1=max,min1=min;
        int max2=max,min2=min;
        DAC(v,i,mid,max1,min1);
        DAC(v,mid+1,j,max2,min2);
        
        if(max1<max2) 
          max=max2;
         else 
          max= max1; 
        if(min1>min2) 
          min=min2;
         else 
          min= min1;   

    } 
}

int main(void)
{
    int n;
    cout<<"\n\nEnter n: ";
    cin >> n;
    vector<int> v(n);
    cout<<endl<<"Enter values: ";
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }

    int max=INT_MIN,min=INT_MAX;
    DAC(v,0,v.size()-1,max,min);
    cout<<"MAX: "<<max<<"  "<<"MIN: "<<min<<endl;


    return 0;
}

/* 
     5
     3 2 5 -123 234

*/