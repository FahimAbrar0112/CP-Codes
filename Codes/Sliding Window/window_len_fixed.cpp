#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the maximum average of any subarray of length `k` in the given vector `nums`.
 *
 * The algorithm uses a sliding window approach to efficiently calculate the sum of consecutive subarrays
 * of length `k` and keeps track of the maximum average encountered.
 */
class Solution
{
public:
    // K => size of the window
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size(); // Length of the input vector
        int currentSum = 0;  // Holds the sum of the current subarray of length `k`

        // Calculate the sum of the first `k` elements
        for (int i = 0; i < k; i++)
        {
            currentSum += nums[i];
        }

        // Initialize the max average with the average of the first subarray of length `k`
        double maxAvg = ((double)currentSum) / k;

        // Sliding window: slide the window across the array, update sum and max average
        for (int i = k; i < n; i++)
        {
            currentSum += nums[i];                        // Add the next element to the window
            currentSum -= nums[i - k];                    // Remove the element that is no longer in the window
            double currentAvg = ((double)currentSum) / k; // Calculate the average of the current window
            maxAvg = max(maxAvg, currentAvg);             // Update the maximum average if necessary
        }

        return maxAvg; // Return the maximum average found
    }
};

int main(void)
{
}