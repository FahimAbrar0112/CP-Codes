#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {

        int lo = 0, hi = nums.size() - 1;

        cout << lo << " 1>" << hi << endl;
        if (target < nums[0])

            return 0;
        if (nums[hi] < target)

            return hi + 1;

        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;

            if (target < nums[mid])

                hi = mid;

            else
                lo = mid;
        }

        if (nums[lo] == target)
            return lo;
        if (nums[hi] == target)
            return hi;

        return hi;
    }
};

int main()
{

    Solution S;
    vector<int> v = {1, 3, 5, 6};
    cout << S.searchInsert(v, 5) << endl;
}