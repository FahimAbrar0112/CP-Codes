// https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>
using namespace std;

// Sliding Window:

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, currSum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < nums.size(); right++)
        {

            currSum += nums[right];
            while (currSum >= target)
            {
                minLen = min(minLen, right - left + 1);
                currSum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main(void)
{
}