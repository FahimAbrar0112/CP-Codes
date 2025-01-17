#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    int i = 0;
    for (auto pair : mp)
    {
        if (pair.second > 2)
            pair.second = 2;

        while (pair.second != 0)
        {
            nums[i] = pair.first;
            pair.second--;
            i++;
        }
    }
    return i;
}

int main(void)
{
}