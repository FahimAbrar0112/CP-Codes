#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n), pref(n), suff(n);
    int mul = 1;

    for (int i = 0; i < n; i++)
    {
        pref[i] = mul * nums[i];
        mul = pref[i];
    }

    mul = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        suff[i] = mul * nums[i];
        mul = suff[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            ans[i] = suff[i + 1];
        else if (i == n - 1)
            ans[i] = pref[i - 1];
        else
            ans[i] = pref[i - 1] * suff[i + 1];
    }

    return ans;
}

// Alternative:

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> output(nums.size(), 1);

        int left = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            output[i] *= left;
            left *= nums[i];
        }

        int right = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            output[i] *= right;
            right *= nums[i];
        }

        return output;
    }
};
