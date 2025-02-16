#include <bits/stdc++.h>
using namespace std;
 
class Solution
{
public:
    vector<vector<int>> valied;
    vector<bool> visited;

    void generate(vector<int> &sub, vector<int> &nums)
    {
        if (sub.size() == nums.size())
        {
            valied.push_back(sub);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                sub.push_back(nums[i]);
                visited[i] = true;

                generate(sub, nums);

                sub.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        visited = vector<bool>(nums.size(), false);
        vector<int> sub;
        generate(sub, nums);
        return valied;
    }
};


