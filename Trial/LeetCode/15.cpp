#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // Initialize a vector to store the result triplets
        vector<vector<int>> result;

        // Sort the input array to allow the use of two-pointer technique
        sort(nums.begin(), nums.end());

        // Iterate through the array, fixing one number at a time
        for (int i = 0; i < nums.size() - 2; i++)
        {
            // Skip duplicate values for the first number
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Set the target value as the negative of the fixed number
            int target = -nums[i];

            // Initialize two pointers
            int left = i + 1, right = nums.size() - 1;

            // Use the two-pointer technique to find pairs that sum to the target
            while (left < right)
            {
                int sum = nums[left] + nums[right];

                if (sum < target)
                {
                    // If the sum is less than the target, move the left pointer forward
                    left++;
                }
                else if (sum > target)
                {
                    // If the sum is greater than the target, move the right pointer backward
                    right--;
                }
                else
                {
                    // If a triplet is found, add it to the result
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values for the left pointer
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }

                    // Skip duplicate values for the right pointer
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }

                    // Move both pointers after processing the current triplet
                    left++;
                    right--;
                }
            }
        }

        // Return the list of triplets
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-4, 2, 2, 2, 2, 2};
    vector<vector<int>> result = sol.threeSum(nums);

    for (const auto &triplet : result)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}