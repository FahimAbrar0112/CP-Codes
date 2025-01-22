// https : // leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>
        using namespace std;

// Binary Search:
class Solution
{
public:
    


    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        int minLen = INT_MAX;
        for (int i = 1; i <= n; i++)
        {

            int lo = i, hi = n;

            while (hi - lo > 1)
            {
                int mid = (lo + hi) / 2;
                int currSum = prefixSum[mid] - prefixSum[i - 1];

                if (currSum >= target)
                {
                    minLen = min(minLen, mid - i + 1);
                    hi = mid;
                }
                else
                    lo = mid + 1;
            }

            if ((prefixSum[lo] - prefixSum[i - 1]) >= target)

                minLen = min(minLen, lo - i + 1);

            else if ((prefixSum[hi] - prefixSum[i - 1]) >= target)

                minLen = min(minLen, hi - i + 1);
            // else if => To ensure minLen is only updated when a valid subarray exists, the correct approach should be:
            /*
                Scenario:
                Suppose after the binary search:
                lo = 3, hi = 4
                Given subarrays:
                prefixSum[3] - prefixSum[i - 1] = 6 (false, doesn't satisfy target)
                prefixSum[4] - prefixSum[i - 1] = 6 (false, also doesn't satisfy target)
                Initially, minLen = 5.
                So, without else if , minLen gets changed and causes WA.
            */
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};
 
 // Sliding Window:


class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    { 
        int left=0, currSum=0;
        int minLen=INT_MAX;

        for(int right=0;right<nums.size();right++)
        {

            currSum+=nums[right];
            while(currSum>=target)
            {
                minLen=min(minLen,right-left+1);
                currSum-=nums[left];
                left++;
            }

        }
        return minLen==INT_MAX?0:minLen;
    }
};