#include <bits/stdc++.h>
using namespace std;
bool isValied(int val, vector<int> &citations)
{
    int ct = 0;
    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] >= val)
            ct++;
    }
    return ct >= val;
}

int binarySearch(vector<int> &citations)
{
    int lo = 0, hi = 1e5;

    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        if (isValied(mid, citations))

            lo = mid;

        else
            hi = mid - 1;
    }

    if (isValied(hi, citations))
        return hi;
    return lo;
}

int hIndex(vector<int> &citations)
{   
    return binarySearch(citations);
}

int main(void)
{
}