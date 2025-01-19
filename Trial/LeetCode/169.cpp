#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n / 2];
    }
};


// OR, 

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        int ct = -1;
        int ans;

        for (auto pair : mp)
        {
            if (pair.second > ct)
            {
                ans = pair.first;
                ct = pair.second;
            }
             
        }
        return ans;
    }
};


 