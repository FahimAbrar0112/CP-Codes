#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;
int a[N];
// 1 2  3 4 5  7 8  9   4 5 6 7
void merge(int l,int r,int mid)
{
    int l_s = mid-l+1;
    int r_s = r-(mid+1)+1 ;
    int L[l_s+1];
    int R[r_s+1];
    for(int i=0;i<l_s;i++)
    {
        L[i]=a[i+l];
    }
    for(int i=0;i<r_s;i++)
    {
        R[i]=a[i+mid+1];
    }

    L[l_s]=R[r_s]=INT_MAX;
    
    //merge two sorted arrays into one array in ascending order.
    int indL=0,indR=0;
    for(int i=l;i<=r;i++)
    {
        if(L[indL]<R[indR])
        {
            a[i]=L[indL];
            indL++;
        }
        else
        {
            a[i]=R[indR];
            indR++;
        }
        
    }

}

void meergeSort(int l,int r)
{
    if(l==r) return; 
    int mid=(l+r)/2;
    meergeSort(l,mid);
    meergeSort(mid+1,r);
    merge(l,r,mid);

}



int main(void)
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    meergeSort(0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    


    return 0;
}
