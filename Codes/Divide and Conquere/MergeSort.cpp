#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

/**
 *       0    1  2  3 4  5  6  7
 *       10  20 30 40 11 21 31 41
 *       p          q           r
 *
 *      n1=q-p+1=3-0+1=4
 *      n2=r-q=7-3=4
 */
void merge(vector<int> &v, int p, int q, int r);
void mergeSort(vector<int> &v, int p, int r);

void mergeSort(vector<int> &v, int p, int r)
{
    if (p >= r)
        return;

    int q = (p + r) / 2;

    mergeSort(v, p, q);
    mergeSort(v, q + 1, r);
    merge(v, p, q, r);
}

void merge(vector<int> &v, int p, int q, int r)
{ /*
     p = starting index of vector
     q=mid ind
     r= ending index of vector
   */

    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);

    for (int i = 0; i < n1; i++)
    {
        L[i] = v[p + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = v[q + i + 1];
    }

    L[n1] = INF;
    R[n2] = INF;

    int i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
    }
}

int main(void)
{
    int n;
    cout<<"Enter # of values: ";
    cin>>n;
    vector<int>v(n);
    cout<<endl<<"Enter values: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
        
        
    mergeSort(v, 0, v.size() - 1);


    for (auto it : v)
    {
        cout << it << " ";
    }

    return 0;
}