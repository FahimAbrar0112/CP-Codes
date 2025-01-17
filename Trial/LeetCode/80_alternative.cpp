#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int INF = INT_MAX;
        int count = 1;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (prev == nums[i])
            {
                if (count >= 2)
                {
                    nums[i] = INF;
                }
                else
                {
                    count++;
                }
            }
            else
            {
                prev = nums[i];
                count = 1;
            }
        }
        sort(nums.begin(), nums.end());
        count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != INF)
                count++;
        }
        return count;
    }
};