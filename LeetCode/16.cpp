#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int closestSum = 0;
        int minDistance = INT_MAX;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1, right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                // Check the absolute distance to the target
                int dist = abs(target - sum);
                if (dist < minDistance)
                {
                    minDistance = dist;
                    closestSum = sum;
                }

                if (sum < target)
                {
                    left++; // Increase sum by moving left pointer
                }
                else if (sum > target)
                {
                    right--; // Decrease sum by moving right pointer
                }
                else
                {
                    return sum; // Exact match found
                }
            }
        }
        return closestSum;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << "Closest sum to " << target << " is " << sol.threeSumClosest(nums, target) << endl;
    return 0;
}
