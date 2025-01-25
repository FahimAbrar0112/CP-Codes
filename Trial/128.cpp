#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        unordered_set<int> exist(nums.begin(),nums.end());

        int longest=0;

        for(int num:exist)
        {
            if(exist.count(num-1)) continue;

            int ct=1;
            while (exist.count(num+1))
            {
                exist.erase(num+1);
                
                ct++;
                num++;
            }

            longest=max(longest,ct);
            
        }

        return longest;


    }
};





class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if(nums.size()==0) return 0;
        int ans=1,tmp=1;

        sort(nums.begin(),nums.end());

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]+1==nums[i])
            {
                tmp++;
                
            }
            else if(nums[i-1]==nums[i])
            {
                continue;
            }
            else
            {
                tmp=1;
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};
