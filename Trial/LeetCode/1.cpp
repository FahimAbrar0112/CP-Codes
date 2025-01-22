#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        vector<int> ans;
        vector<pair<int, int>> v;

        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back({nums[i], i});
        }

        sort(v.begin(),v.end());

        auto left = v.begin();
        auto right = --(v.end());

        while (left < right)
        {
            int sum = left->first + right->first;

            if (sum == target)
            {
                ans.push_back(left->second);
                ans.push_back(right->second);
                break;
            }

            if (sum < target)
            {
                left++;
            }
            if (sum > target)
            {
                right--;
            }
        }
        return ans;
    }
};

int main(void)
{
}