#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> valied;

    void generate(vector<int> &candidates, int target, vector<int> &sub,int index)
    {
        if (target == 0)
        {
            valied.push_back(sub);
            return;
        }
        if (target < 0)
            return;

        for (int i = index; i < candidates.size(); i++)
        {
            sub.push_back(candidates[i]);
            generate(candidates, target - candidates[i], sub,i);
            sub.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int>sub;
        generate(candidates,target,sub,0);
        return valied;
    }
};
