#include <bits/stdc++.h>
using namespace std;

 
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int jumps = 0, current_end = 0, farthest = 0;

        for (int i = 0; i < n - 1; ++i)
        {
            farthest = max(farthest, i + nums[i]);
            if (i == current_end)
            {
                ++jumps;
                current_end = farthest;
            }
        }
        return jumps;
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
