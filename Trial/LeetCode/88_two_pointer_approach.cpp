#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    int arrL[m + 1];
    int arrR[n + 1];

    arrL[m] = INT_MAX;
    arrR[n] = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        arrL[i] = nums1[i];
    }

    for (int i = 0; i < n; i++)
    {
        arrR[i] = nums2[i];
    }

    int l_i = 0;
    int r_i = 0;

    for (int i = 0; i < m + n; i++)
    {
        if (arrL[l_i] <= arrR[r_i])
        {
            nums1[i] = arrL[l_i];
            l_i++;
        }
        else
        {
            nums1[i] = arrR[r_i];
            r_i++;
        }
    }
    
}

int main(void)
{
}