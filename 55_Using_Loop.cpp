#include <bits/stdc++.h>
using namespace std;


// Last theke index 0 te ashar try korteso
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int goal = nums.size() - 1;

        for (int currentPosition = nums.size() - 2; currentPosition >= 0; currentPosition--)
        {
            if (currentPosition + nums[currentPosition] >= goal)
                goal = currentPosition;
        }
        return goal == 0;
    }
};
int main(void)
{
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};
    Solution S;
    cout << S.canJump(nums1) << endl;
    cout << S.canJump(nums2) << endl;
}