#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{

    int n = nums.size();
    k %= n;
    if (k == 0)
        return;

    vector<int> tmp(n);

    for (int i = 0; i < n; i++)
    {
        tmp[(i + k) % n] = nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = tmp[i];
    }
    return;
}

int main(void)
{
}