// https : // leetcode.com/problems/partition-equal-subset-sum/description/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

bool func(int ind, int sumLeft, vector<int> &nums)
{
    if (sumLeft == 0)
        return 1;
    if (ind < 0)
        return 0;
    if (dp[ind][sumLeft] != -1)
        return dp[ind][sumLeft];

    int isPossible = func(ind - 1, sumLeft, nums);
    if (sumLeft - nums[ind] >= 0)
        isPossible |= func(ind - 1, sumLeft - nums[ind], nums);

    return dp[ind][sumLeft] = isPossible;
}

bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
        return 0;
    sum /= 2;
    dp.resize(nums.size() + 1, vector<int>(sum + 1, -1));

    return func(nums.size() - 1, sum, nums);
}

int main(void)
{
    vector<int> nums = {1,5,11,5};
    cout<<canPartition(nums)<<endl;
}