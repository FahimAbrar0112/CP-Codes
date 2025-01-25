#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {

        vector<pair<int, int>> p;
        for (int i = 0; i < nums.size(); i++)
        {
            p.push_back({nums[i], i});
        }

        sort(p.begin(), p.end());

        for (auto val : p)
        {
            cout << val.first << "  " << val.second << endl;
        }

        for (int i = 0; i < p.size() - 1; i++)
        {

            if (p[i].first == p[i + 1].first && (abs(p[i].second - p[i + 1].second) <= k))
                return 1;
        }
        return 0;
    }
};

 
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++)
        {

            if (window.count(nums[i]))
                return 1;

            window.insert(nums[i]);

            if (window.size() > k)
            {
                window.erase(nums[i - k]);
            }
        }

        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    cout << (sol.containsNearbyDuplicate(nums, k) ? "True" : "False") << endl;

    return 0;
}
