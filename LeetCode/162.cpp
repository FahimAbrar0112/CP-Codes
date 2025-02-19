#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        multiset<pair<int, int>> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert({nums[i], i});
        }
        auto it = --(s.end());
        return it->second;
    }
};
