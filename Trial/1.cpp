#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

void mergeSort(vector<int> &v, int l, int r);
void merge(vector<int> &v, int l, int mid, int r);

void mergeSort(vector<int> &v, int l, int r)
{
     if (l == r)
          return;
     int mid = (l + r) / 2;

     mergeSort(v, l, mid);
     mergeSort(v, mid + 1, r);

     merge(v, l, mid, r);
}

void merge(vector<int> &v, int l, int mid, int r)
{
     int l_s = mid - l + 1;
     int r_s = r - mid;

     vector<int> L(l_s + 1);
     vector<int> R(r_s + 1);
     L[l_s] = INT_MAX;
     R[r_s] = INT_MAX;

     for (int i = 0; i < l_s; i++)
     {
          L[i] = v[i + l];
     }

     for (int i = 0; i < r_s; i++)
     {
          R[i] = v[i + mid + 1];
     }

     int l_i = 0, r_i = 0;
     for (int k = l; k <= r; k++)
     {
          if (L[l_i] <= R[r_i])
          {
               v[k] = L[l_i];
               l_i++;
          }
          else
          {
               v[k] = R[r_i];
               r_i++;
          }
     }
}

int main(void)
{
     vector<int> v = {5, 4, 2, 1, 8, 21, 56, 2, 12, -34};

     mergeSort(v, 0, 4);
     for(auto it:v)
     {
          cout<<it<<" ";
     }
     return 0;
}