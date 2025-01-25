#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        int n = nums.size();
        if (n == 0)
            return ans;

        int start = 0;

        for (int i = 1; i <= n; i++)
        {
            // When we reach the end of the array or a break in the sequence
            if (i == n || (nums[i] != nums[i - 1] + 1))
            {
                // If start equals i-1, it's a single number
                if (start == i - 1)
                {
                    ans.push_back(to_string(nums[start]));
                }
                else
                {
                    // Otherwise, it's a range
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
                }
                start = i; // Update start to the current number
            }
        }
 

        return ans;
    }
};
