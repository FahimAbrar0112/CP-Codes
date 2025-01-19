#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int N = 1e4 + 10;
    vector<int> dp;
    bool func(int index, vector<int> &nums)
    {
        if (index == nums.size() - 1)
            return 1;
        if (dp[index] != -1)
            return dp[index];
        bool ans = 0;
        for (int step = 1; step <= nums[index]; step++)
        {
            ans |= func(index + step, nums);
            if (ans)
                break;
        }

        return dp[index] = ans;
    }

    bool canJump(vector<int> &nums)
    {
        dp.resize(N, -1);
        return func(0, nums);
    }
};

int main(void)
{
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};
    Solution S;
    // cout << S.canJump(nums1) << endl;
    cout << S.canJump(nums2) << endl;
}