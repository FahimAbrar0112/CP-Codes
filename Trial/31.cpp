#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int ind = -1;

        // Step 1: Find the first decreasing element from the right (pivot)
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                ind = i;
                break;
            }
        }

        // If no pivot found, reverse to get the smallest permutation
        if (ind == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the next largest element to swap from the end
        for (int i = n - 1; i > ind; i--)
        {
            if (nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 3: Reverse the right part after pivot to get the next permutation
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
