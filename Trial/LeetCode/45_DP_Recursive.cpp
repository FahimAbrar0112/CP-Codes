#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int N = 1e4 + 10;
    vector<int> dp;
    int func(int index, vector<int> &nums)
    {
        if (index == nums.size() - 1)
            return 0;
        if (dp[index] != -1)
            return dp[index];

        long long minJump = INT_MAX;

        for (int step = 1; step <= nums[index]; step++)
        {
            if (index + step < nums.size())
                minJump = min(minJump, func(index + step, nums) + 1ll);
        }

        return dp[index] = minJump;
    }

    int jump(vector<int> &nums)
    {
        dp.resize(nums.size() + 1, -1);
        return func(0, nums);
    }
};

int main(void)
{
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {1, 3, 1, 3, 0, 0, 4};

    Solution S;
    // cout << S.jump(nums1) << endl;
    cout << S.jump(nums2) << endl;
}
